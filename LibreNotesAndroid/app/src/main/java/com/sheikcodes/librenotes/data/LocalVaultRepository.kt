package com.sheikcodes.librenotes.data

import android.content.Context
import com.sheikcodes.librenotes.model.AppSettings
import com.sheikcodes.librenotes.model.Note
import com.sheikcodes.librenotes.model.ThemeMode
import org.json.JSONArray
import org.json.JSONObject
import java.io.File

class LocalVaultRepository(context: Context) {
    private val appContext = context.applicationContext
    private val notesFile = File(appContext.filesDir, "librenotes-vault.json")
    private val settingsFile = File(appContext.filesDir, "librenotes-settings.json")

    fun loadNotes(): List<Note> {
        if (!notesFile.exists()) {
            val seeded = seedNotes()
            saveNotes(seeded)
            return seeded
        }

        return runCatching {
            val raw = notesFile.readText()
            if (raw.isBlank()) {
                emptyList()
            } else {
                val json = JSONArray(raw)
                buildList {
                    for (index in 0 until json.length()) {
                        add(json.getJSONObject(index).toNote())
                    }
                }
            }
        }.getOrElse {
            val seeded = seedNotes()
            saveNotes(seeded)
            seeded
        }
    }

    fun saveNotes(notes: List<Note>) {
        notesFile.parentFile?.mkdirs()
        val payload = JSONArray()
        notes.forEach { note ->
            payload.put(note.toJson())
        }
        notesFile.writeText(payload.toString(2))
    }

    fun loadSettings(): AppSettings {
        if (!settingsFile.exists()) {
            return AppSettings()
        }

        return runCatching {
            val json = JSONObject(settingsFile.readText())
            AppSettings(
                themeMode = ThemeMode.valueOf(json.optString("themeMode", ThemeMode.SYSTEM.name))
            )
        }.getOrDefault(AppSettings())
    }

    fun saveSettings(settings: AppSettings) {
        settingsFile.parentFile?.mkdirs()
        val json = JSONObject()
            .put("themeMode", settings.themeMode.name)
        settingsFile.writeText(json.toString(2))
    }

    fun exportVault(notes: List<Note>, settings: AppSettings): String {
        val root = JSONObject()
            .put("app", "LibreNotes")
            .put("exportedAt", System.currentTimeMillis())
            .put("settings", JSONObject().put("themeMode", settings.themeMode.name))

        val notesJson = JSONArray()
        notes.forEach { notesJson.put(it.toJson()) }
        root.put("notes", notesJson)

        return root.toString(2)
    }

    fun reinstallDemoNotes(existing: List<Note>): List<Note> {
        val merged = LinkedHashMap<String, Note>()
        seedNotes().forEach { note ->
            merged[note.title.trim().lowercase()] = note
        }
        existing.forEach { note ->
            merged[note.title.trim().lowercase()] = note
        }
        return merged.values.toList()
    }

    private fun JSONObject.toNote(): Note = Note(
        id = optString("id"),
        title = optString("title"),
        content = optString("content"),
        tags = buildList {
            val tagsArray = optJSONArray("tags") ?: JSONArray()
            for (index in 0 until tagsArray.length()) {
                add(tagsArray.optString(index))
            }
        },
        isPinned = optBoolean("isPinned", false),
        createdAt = optLong("createdAt", System.currentTimeMillis()),
        updatedAt = optLong("updatedAt", System.currentTimeMillis())
    )

    private fun Note.toJson(): JSONObject {
        val tagsArray = JSONArray()
        tags.forEach { tagsArray.put(it) }

        return JSONObject()
            .put("id", id)
            .put("title", title)
            .put("content", content)
            .put("tags", tagsArray)
            .put("isPinned", isPinned)
            .put("createdAt", createdAt)
            .put("updatedAt", updatedAt)
    }

    private fun seedNotes(): List<Note> {
        val focusNote = Note(
            title = "Focus ritual",
            content = """
                # Focus ritual
                
                - [ ] Start a 25 minute session
                - [ ] Put the phone away
                - [ ] Open [[Daily desk]]
                
                > Keep the capture surface calm and local.
                
                #deep-work
            """.trimIndent(),
            tags = listOf("routine", "focus"),
            isPinned = true
        )
        val dailyDesk = Note(
            title = "Daily desk",
            content = """
                # Daily desk
                
                Today's scratchpad lives here.
                
                Link out to [[Project map]] when an idea becomes real.
                Check in with [[Focus ritual]] before writing.
                
                ## Prompts
                - What matters today?
                - What can wait?
                - Which note should become a permanent note?
                
                #today
            """.trimIndent(),
            tags = listOf("daily", "journal")
        )
        val projectMap = Note(
            title = "Project map",
            content = """
                # Project map
                
                ## Current tracks
                - Android MVP
                - Offline search
                - Linking and backlinks
                
                Related notes:
                - [[Daily desk]]
                - [[Idea nursery]]
                
                #planning
            """.trimIndent(),
            tags = listOf("planning", "roadmap")
        )
        val ideaNursery = Note(
            title = "Idea nursery",
            content = """
                # Idea nursery
                
                Small ideas that do not deserve a full project yet.
                
                - Ambient focus sounds
                - On-device lock screen
                - Export bundles for [[Project map]]
                
                #ideas
            """.trimIndent(),
            tags = listOf("ideas")
        )

        return listOf(focusNote, dailyDesk, projectMap, ideaNursery)
    }
}
