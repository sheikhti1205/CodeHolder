package com.sheikcodes.librenotes.ui.theme

import androidx.compose.foundation.isSystemInDarkTheme
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Shapes
import androidx.compose.material3.Typography
import androidx.compose.material3.darkColorScheme
import androidx.compose.material3.lightColorScheme
import androidx.compose.runtime.Composable
import androidx.compose.ui.unit.dp
import com.sheikcodes.librenotes.model.ThemeMode

private val LightColors = lightColorScheme(
    primary = Moss,
    onPrimary = Paper,
    secondary = Terracotta,
    onSecondary = Paper,
    tertiary = SkyDust,
    background = Paper,
    onBackground = Bark,
    surface = Color(0xFFFFFBF5),
    onSurface = Bark,
    surfaceVariant = PaperWarm,
    onSurfaceVariant = BarkSoft
)

private val DarkColors = darkColorScheme(
    primary = Sand,
    onPrimary = Night,
    secondary = Terracotta,
    onSecondary = Night,
    tertiary = SkyDust,
    background = Night,
    onBackground = Paper,
    surface = NightSurface,
    onSurface = Paper,
    surfaceVariant = NightSurfaceSoft,
    onSurfaceVariant = SandSoft
)

@Composable
fun LibreNotesTheme(
    themeMode: ThemeMode,
    content: @Composable () -> Unit
) {
    val useDark = when (themeMode) {
        ThemeMode.SYSTEM -> isSystemInDarkTheme()
        ThemeMode.LIGHT -> false
        ThemeMode.DARK -> true
    }

    MaterialTheme(
        colorScheme = if (useDark) DarkColors else LightColors,
        typography = Typography(),
        shapes = Shapes(
            small = androidx.compose.foundation.shape.RoundedCornerShape(14.dp),
            medium = androidx.compose.foundation.shape.RoundedCornerShape(20.dp),
            large = androidx.compose.foundation.shape.RoundedCornerShape(28.dp)
        ),
        content = content
    )
}
