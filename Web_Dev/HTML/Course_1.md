# HTML Fundamentals — Concise Study Notes

## 1. What is HTML

**HTML (HyperText Markup Language)** is the standard language used to create the **structure of webpages**.

It tells the browser:

* what content exists
* how content is organized
* how elements relate to each other

### Key Meaning

* **HyperText** → Clickable text that links to other pages or resources.
* **Markup** → Special tags that annotate text to define its structure.
* **Language** → A syntax browsers understand to render webpages.

HTML was introduced in **1991 by Tim Berners-Lee** to connect and share documents through the web.

---

# 2. Basic HTML Document Structure

Every HTML file follows a standard structure.

```html
<!DOCTYPE html>
<html>

<head>
    <title>My First Webpage</title>
</head>

<body>

    <h1>Hello World</h1>
    <p>This is my first webpage.</p>

</body>

</html>
```

### Structure Breakdown

| Element           | Purpose                           |
| ----------------- | --------------------------------- |
| `<!DOCTYPE html>` | Declares HTML5 document           |
| `<html>`          | Root element of webpage           |
| `<head>`          | Metadata (title, styles, scripts) |
| `<title>`         | Browser tab title                 |
| `<body>`          | Visible page content              |

---

# 3. HTML Elements

An **HTML element** usually has:

```
<tag> content </tag>
```

Example:

```
<p>This is a paragraph</p>
```

### Parts of an Element

| Part      | Example |
| --------- | ------- |
| Start tag | `<p>`   |
| Content   | text    |
| End tag   | `</p>`  |

---

# 4. Headings

HTML provides **six heading levels**.

```html
<h1>Main Heading</h1>
<h2>Sub Heading</h2>
<h3>Section Heading</h3>
<h4>Small Heading</h4>
<h5>Very Small Heading</h5>
<h6>Tiny Heading</h6>
```

### Characteristics

* `<h1>` is largest and most important
* `<h6>` is smallest
* Used for **content hierarchy**

---

# 5. Paragraphs

Paragraphs define blocks of text.

```html
<p>This is a paragraph of text.</p>
```

Characteristics:

* Automatically starts on a new line
* Used for longer text content

---

# 6. HTML Comments

Comments are notes in the code and **not visible in the webpage**.

```
<!-- This is a comment -->
```

Shortcut in most editors:

```
Ctrl + /
```

Used for:

* documentation
* debugging
* disabling code temporarily

---

# 7. Text Formatting Tags

HTML provides tags to modify text appearance and meaning.

| Tag        | Function                     |
| ---------- | ---------------------------- |
| `<b>`      | Bold text                    |
| `<strong>` | Important text               |
| `<i>`      | Italic text                  |
| `<em>`     | Emphasized text              |
| `<mark>`   | Highlighted text             |
| `<small>`  | Smaller text                 |
| `<del>`    | Deleted / strikethrough text |
| `<sup>`    | Superscript                  |
| `<sub>`    | Subscript                    |

### Example

```html
<p>This is <strong>important</strong> text.</p>
<p>H<sub>2</sub>O is water.</p>
<p>10<sup>2</sup> = 100</p>
```

---

# 8. HTML Attributes

Attributes provide **extra information about elements**.

Syntax:

```
<tag attribute="value">
```

Example:

```html
<p id="intro" title="introduction paragraph">
Hello World
</p>
```

### Common Attributes

| Attribute | Purpose           |
| --------- | ----------------- |
| `id`      | unique identifier |
| `title`   | tooltip text      |
| `style`   | inline CSS        |
| `class`   | grouping elements |
| `src`     | media source      |
| `href`    | link destination  |

Example:

```html
<p style="color:blue;">Blue text</p>
```

---

# 9. Hyperlinks

Links connect webpages or resources.

```html
<a href="https://google.com">Visit Google</a>
```

### Opening in a New Tab

```html
<a href="https://google.com" target="_blank">
Open Google
</a>
```

### Important Attributes

| Attribute | Purpose          |
| --------- | ---------------- |
| `href`    | destination URL  |
| `target`  | where link opens |

---

# 10. Images

Images are inserted using the `<img>` tag.

```html
<img src="image.jpg" alt="A photo">
```

### Important Attributes

| Attribute | Function         |
| --------- | ---------------- |
| `src`     | image path       |
| `alt`     | alternative text |
| `width`   | image width      |
| `height`  | image height     |

Example:

```html
<img src="cat.jpg" alt="Cute cat" width="300">
```

Note:
`<img>` is a **self-closing tag**.

---

# 11. Lists

Lists organize related items.

## Unordered List (Bullet Points)

```html
<ul>
<li>Apple</li>
<li>Banana</li>
<li>Mango</li>
</ul>
```

## Ordered List (Numbered)

```html
<ol>
<li>Wake up</li>
<li>Study</li>
<li>Sleep</li>
</ol>
```

### Ordered List Types

```html
<ol type="A">
<ol type="a">
<ol type="I">
<ol type="i">
```

---

# 12. Block vs Inline Elements

## Block Elements

* Take full width
* Start on a new line

Examples

```
<h1>
<p>
<div>
<ul>
```

## Inline Elements

* Only use necessary width
* Stay on same line

Examples

```
<a>
<img>
<span>
<strong>
```

---

# 13. Audio Embedding

Audio can be embedded with the `<audio>` tag.

```html
<audio controls>
<source src="song.mp3" type="audio/mpeg">
</audio>
```

### Attributes

| Attribute  | Purpose             |
| ---------- | ------------------- |
| `controls` | show audio player   |
| `autoplay` | start automatically |
| `loop`     | repeat audio        |
| `muted`    | start muted         |

---

# 14. Video Embedding

Video is embedded with `<video>`.

```html
<video width="400" controls>
<source src="video.mp4" type="video/mp4">
</video>
```

### Common Attributes

| Attribute  | Function           |
| ---------- | ------------------ |
| `width`    | video width        |
| `height`   | video height       |
| `controls` | show player        |
| `autoplay` | play automatically |
| `loop`     | repeat video       |

---

# 15. Line Breaks and Horizontal Lines

### Line Break

```
<br>
```

Moves text to a new line.

### Horizontal Line

```
<hr>
```

Creates a visual separator.

---

# 16. Good Development Practices

* Save code frequently (`Ctrl + S`)
* Refresh browser to see updates
* Use clear folder structures
* Write readable code
* Use comments to explain sections

---

# 17. Essential HTML Tags Overview

| Tag           | Purpose         |
| ------------- | --------------- |
| `<html>`      | root element    |
| `<head>`      | metadata        |
| `<title>`     | page title      |
| `<body>`      | visible content |
| `<h1>`–`<h6>` | headings        |
| `<p>`         | paragraph       |
| `<a>`         | hyperlink       |
| `<img>`       | image           |
| `<ul>`        | unordered list  |
| `<ol>`        | ordered list    |
| `<li>`        | list item       |
| `<audio>`     | audio player    |
| `<video>`     | video player    |
| `<br>`        | line break      |
| `<hr>`        | horizontal line |

---

# Core Understanding

HTML provides the **structural foundation of the web**.
Every webpage is built by combining:

* elements
* attributes
* text content
* media resources

CSS and JavaScript later extend this foundation by adding **design and interactivity**.

---

✅ **Best way to learn HTML**

1. Write small webpages.
2. Experiment with tags.
3. Build mini projects.
4. Practice daily.

---

