package com.sheikcodes.librenotes.model

import java.util.UUID

enum class ThemeMode {
    SYSTEM,
    LIGHT,
    DARK
}

data class AppSettings(
    val themeMode: ThemeMode = ThemeMode.SYSTEM
)

data class Note(
    val id: String = UUID.randomUUID().toString(),
    val title: String,
    val content: String,
    val tags: List<String> = emptyList(),
    val isPinned: Boolean = false,
    val createdAt: Long = System.currentTimeMillis(),
    val updatedAt: Long = createdAt
) {
    fun displayTitle(): String = title.ifBlank { NoteParsers.inferTitle(content) }

    fun allTags(): List<String> = (tags + NoteParsers.extractInlineTags(content)).normalizedDistinct()

    fun linkTargets(): List<String> = NoteParsers.extractLinks(content)

    fun excerpt(maxLength: Int = 180): String {
        val compact = content.replace("\\s+".toRegex(), " ").trim()
        if (compact.isBlank()) {
            return "Tap to start writing."
        }
        return if (compact.length <= maxLength) compact else "${compact.take(maxLength).trimEnd()}..."
    }
}

data class NoteDraft(
    val noteId: String? = null,
    val title: String = "",
    val content: String = "",
    val tagsText: String = "",
    val isPinned: Boolean = false,
    val createdAt: Long = System.currentTimeMillis()
)

fun Note.toDraft(): NoteDraft = NoteDraft(
    noteId = id,
    title = title,
    content = content,
    tagsText = tags.joinToString(", "),
    isPinned = isPinned,
    createdAt = createdAt
)

fun NoteDraft.toNote(existing: Note? = null): Note {
    val cleanedTitle = title.trim()
    val normalizedTags = tagsText
        .split(",", "\n")
        .map { it.trim().trimStart('#') }
        .filter { it.isNotBlank() }
        .normalizedDistinct()
    val resolvedTitle = cleanedTitle.ifBlank {
        NoteParsers.inferTitle(content)
    }
    val now = System.currentTimeMillis()

    return Note(
        id = existing?.id ?: noteId ?: UUID.randomUUID().toString(),
        title = resolvedTitle,
        content = content.trimEnd(),
        tags = normalizedTags,
        isPinned = isPinned,
        createdAt = existing?.createdAt ?: createdAt,
        updatedAt = now
    )
}

object NoteParsers {
    private val linkRegex = Regex("\\[\\[([^\\]]+)]]")
    private val tagRegex = Regex("(?<!\\w)#([A-Za-z0-9_-]+)")

    fun extractLinks(content: String): List<String> =
        linkRegex.findAll(content)
            .map { it.groupValues[1].trim() }
            .filter { it.isNotBlank() }
            .distinct()
            .toList()

    fun extractInlineTags(content: String): List<String> =
        tagRegex.findAll(content)
            .map { it.groupValues[1].trim() }
            .filter { it.isNotBlank() }
            .distinct()
            .toList()

    fun inferTitle(content: String): String {
        val line = content
            .lineSequence()
            .map { it.trim() }
            .firstOrNull { it.isNotBlank() }
            ?.removePrefix("#")
            ?.trim()

        return when {
            line.isNullOrBlank() -> "Untitled note"
            line.length <= 48 -> line
            else -> "${line.take(48).trimEnd()}..."
        }
    }

    fun normalizeTitle(title: String): String = title.trim().lowercase()
}

private fun List<String>.normalizedDistinct(): List<String> = this
    .map { it.trim() }
    .filter { it.isNotBlank() }
    .distinctBy { it.lowercase() }
