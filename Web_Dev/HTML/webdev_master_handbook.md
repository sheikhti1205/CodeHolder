# Master Web Development Handbook

## HTML + CSS + Flexbox + Responsive Design

### Clean, detailed, concise, example-heavy study notes


---

# Table of Contents

1. Introduction
2. Chapter 1 — HTML Fundamentals
3. Chapter 2 — Text, Links, Images, Lists
4. Chapter 3 — Tables, Forms, Media, iframe
5. Chapter 4 — Semantic HTML and Page Structure
6. Chapter 5 — CSS Fundamentals
7. Chapter 6 — CSS Selectors, Colors, Text, Box Model
8. Chapter 7 — Display, Position, Units, Flexbox
9. Chapter 8 — Responsive Web Design and Media Queries
10. Chapter 9 — Final Mini Projects
11. Chapter 10 — Quick Revision Cheat Sheet

---

# Introduction

## What is HTML?

HTML stands for **HyperText Markup Language**.  
It is used to create the **structure** of a webpage.

Think of a website like a building:

- **HTML** = structure of the building
- **CSS** = paint, decoration, design
- **JavaScript** = behavior, movement, interactivity

## What is CSS?

CSS stands for **Cascading Style Sheets**.  
It is used to style HTML elements.

Examples:
- change text color
- set background color
- align items
- make layout responsive
- add spacing and borders

---

# Chapter 1 — HTML Fundamentals

## 1.1 Basic HTML Document Structure

Every HTML page usually starts like this:

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>My First Webpage</title>
</head>
<body>
  <h1>Hello World</h1>
  <p>This is my first webpage.</p>
</body>
</html>
````

## Explanation

* `<!DOCTYPE html>` → tells browser this is HTML5
* `<html>` → root element
* `<head>` → contains metadata
* `<meta charset="UTF-8">` → supports characters properly
* `<meta name="viewport"...>` → important for responsive design
* `<title>` → tab title
* `<body>` → visible page content

---

## 1.2 HTML Tags, Elements, and Content

Example:

````html
<p>I am learning HTML.</p>
````
This contains:

* opening tag: `<p>`
* content: `I am learning HTML.`
* closing tag: `</p>`

Some tags have no closing tag, such as:

````html
<br>
<hr>
<img src="image.jpg" alt="Sample image">
````

---

## 1.3 Headings

HTML has 6 heading levels.

````html
<h1>Main Heading</h1>
<h2>Sub Heading</h2>
<h3>Smaller Heading</h3>
<h4>Small Heading</h4>
<h5>Smaller</h5>
<h6>Smallest</h6>
````

### Use case example

````html
<h1>Bangladesh Tourism</h1>
<h2>Sea Beaches</h2>
<h3>Cox's Bazar</h3>
<p>Cox's Bazar is famous for its long natural sea beach.</p>
````

---

## 1.4 Paragraphs

````html
<p>This is a paragraph.</p>
<p>Paragraphs are used to write normal text content.</p>
````

### Example

````html
<p>
Bangladesh is a riverine country. Many people depend on rivers
for transport, fishing, and agriculture.
</p>
````

---

## 1.5 Line Break and Horizontal Rule

### Line Break

````html
<p>Line one<br>Line two<br>Line three</p>
````

### Horizontal Rule

````html
<h2>Section One</h2>
<p>Some text...</p>

<hr>

<h2>Section Two</h2>
<p>More text...</p>
````

---

## 1.6 Comments

Comments are not displayed in browser.

````html
<!-- This is a comment -->
<p>Hello</p>
````

### Example

````html
<!-- Main navigation starts here -->
<nav>
  <a href="#">Home</a>
</nav>
````

---

## 1.7 Final Code for Chapter 1

````html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Chapter 1 Practice</title>
</head>
<body>
  <h1>My First HTML Practice</h1>
  <h2>Introduction</h2>
  <p>Hello, I am learning web development.</p>
  <p>This is my second paragraph.</p>
  <br>
  <p>This line appears after a line break.</p>
  <hr>
  <h2>Conclusion</h2>
  <p>HTML is easy when practiced regularly.</p>
</body>
</html>
````

---

# Chapter 2 — Text, Links, Images, Lists

## 2.1 Text Formatting Tags

````html
<b>Bold text</b>
<strong>Important text</strong>
<i>Italic text</i>
<em>Emphasized text</em>
<mark>Highlighted text</mark>
<small>Small text</small>
<del>Deleted text</del>
H<sub>2</sub>O
x<sup>2</sup>
````

### Example

````html
<p><strong>Warning:</strong> Submit the form carefully.</p>
<p>Chemical formula: H<sub>2</sub>SO<sub>4</sub></p>
<p>Math expression: a<sup>2</sup> + b<sup>2</sup></p>
````

---

## 2.2 Attributes

Attributes add extra information inside the opening tag.

### Examples

````html
<p title="This appears on hover">Hover over me</p>
<p id="intro">Introduction paragraph</p>
<p class="important">This uses a class</p>
````

---

## 2.3 Links

Links use the `<a>` tag.

````html
<a href="https://example.com">Visit Example</a>
````

### Open in new tab

````html
<a href="https://example.com" target="_blank">Open Example</a>
````

### Email link

````html
<a href="mailto:hello@example.com">Send Email</a>
````

### Phone link

````html
<a href="tel:+880123456789">Call Now</a>
````

### Example

````html
<p>
  Visit my
  <a href="https://github.com" target="_blank">GitHub Profile</a>
</p>
````

---

## 2.4 Images

````html
<img src="images/photo.jpg" alt="A description of the image">
````

### Important attributes

* `src` → image path
* `alt` → alternative text
* `width` → width
* `height` → height

### Example 1

````html
<img src="cow.jpg" alt="A cow standing in a field" width="300">
````

### Example 2

````html
<img src="images/profile.png" alt="Profile photo" width="200" height="200">
````

### Image inside a link

````html
<a href="https://example.com">
  <img src="logo.png" alt="Company logo" width="120">
</a>
````

---

## 2.5 Lists

### Unordered List

````html
<ul>
  <li>Rice</li>
  <li>Fish</li>
  <li>Vegetables</li>
</ul>
````

### Ordered List

````html
<ol>
  <li>Wake up</li>
  <li>Study</li>
  <li>Practice coding</li>
</ol>
````

### Ordered list type example

````html
<ol type="A">
  <li>HTML</li>
  <li>CSS</li>
  <li>JavaScript</li>
</ol>
````

### Nested list example

````html
<ul>
  <li>Frontend
    <ul>
      <li>HTML</li>
      <li>CSS</li>
      <li>JavaScript</li>
    </ul>
  </li>
  <li>Backend</li>
</ul>
````

---

## 2.6 Final Code for Chapter 2

````html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Chapter 2 Practice</title>
</head>
<body>
  <h1>Text, Links, Images, Lists</h1>

  <p><strong>Important:</strong> Practice every day.</p>
  <p>Water formula is H<sub>2</sub>O.</p>
  <p>Math power example: x<sup>3</sup></p>

  <p>
    Visit
    <a href="https://developer.mozilla.org" target="_blank">MDN Docs</a>
  </p>

  <img src="profile.jpg" alt="My profile image" width="200">

  <h2>My Skills</h2>
  <ul>
    <li>HTML</li>
    <li>CSS</li>
    <li>Responsive Design</li>
  </ul>

  <h2>Study Steps</h2>
  <ol>
    <li>Read notes</li>
    <li>Write code</li>
    <li>Test in browser</li>
  </ol>
</body>
</html>
````

---

# Chapter 3 — Tables, Forms, Media, iframe

## 3.1 Tables

### Basic table

````html
<table border="1">
  <tr>
    <th>Name</th>
    <th>Age</th>
    <th>City</th>
  </tr>
  <tr>
    <td>Rahim</td>
    <td>22</td>
    <td>Chattogram</td>
  </tr>
  <tr>
    <td>Karim</td>
    <td>21</td>
    <td>Dhaka</td>
  </tr>
</table>
````

### Use case example

````html
<table border="1">
  <tr>
    <th>Course</th>
    <th>Marks</th>
  </tr>
  <tr>
    <td>HTML</td>
    <td>90</td>
  </tr>
  <tr>
    <td>CSS</td>
    <td>88</td>
  </tr>
</table>
````

---

## 3.2 Forms

Forms collect user input.

### Basic form

````html
<form>
  <label>Name:</label>
  <input type="text">

  <label>Email:</label>
  <input type="email">

  <button type="submit">Submit</button>
</form>
````

---

## 3.3 Common Input Types

````html
<input type="text">
<input type="email">
<input type="password">
<input type="number">
<input type="date">
<input type="file">
<input type="color">
<input type="range">
<input type="checkbox">
<input type="radio">
````

### Example with placeholders and required

````html
<input type="text" placeholder="Enter your name" required>
<input type="email" placeholder="Enter your email" required>
````

---

## 3.4 Labels

Labels improve usability and accessibility.

````html
<label for="username">Username</label>
<input type="text" id="username">
````

---

## 3.5 Radio Buttons

Use radio buttons for **one choice only**.

````html
<p>Select your gender:</p>
<input type="radio" id="male" name="gender" value="male">
<label for="male">Male</label>

<input type="radio" id="female" name="gender" value="female">
<label for="female">Female</label>
````

---

## 3.6 Checkboxes

Use checkboxes for **multiple choices**.

````html
<p>Select your skills:</p>
<input type="checkbox" id="html" name="skill" value="html">
<label for="html">HTML</label>

<input type="checkbox" id="css" name="skill" value="css">
<label for="css">CSS</label>

<input type="checkbox" id="js" name="skill" value="js">
<label for="js">JavaScript</label>
````

---

## 3.7 Select Dropdown

````html
<label for="city">Choose a city:</label>
<select id="city">
  <option>Dhaka</option>
  <option>Chattogram</option>
  <option>Khulna</option>
</select>
````

---

## 3.8 Textarea

````html
<label for="message">Message</label>
<textarea id="message" rows="5" cols="30"></textarea>
````

---

## 3.9 Fieldset and Legend

````html
<form>
  <fieldset>
    <legend>Login Form</legend>

    <label for="email">Email</label>
    <input type="email" id="email">

    <label for="password">Password</label>
    <input type="password" id="password">

    <button type="submit">Login</button>
  </fieldset>
</form>
````

---

## 3.10 Audio and Video

### Audio

````html
<audio controls>
  <source src="song.mp3" type="audio/mpeg">
</audio>
````

### Video

````html
<video width="400" controls>
  <source src="movie.mp4" type="video/mp4">
</video>
````

---

## 3.11 iframe

Used to embed another page or media.

### Website example

````html
<iframe src="https://example.com" width="500" height="300"></iframe>
````

### YouTube example

````html
<iframe width="560" height="315"
src="https://www.youtube.com/embed/VIDEO_ID"
title="YouTube video player">
</iframe>
````

### Google Map example

````html
<iframe
  src="https://www.google.com/maps/embed?pb=..."
  width="600"
  height="450"
  style="border:0;"
  loading="lazy">
</iframe>
````

---

## 3.12 Final Code for Chapter 3

````html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Chapter 3 Practice</title>
</head>
<body>
  <h1>Tables and Forms</h1>

  <table border="1">
    <tr>
      <th>Name</th>
      <th>Email</th>
    </tr>
    <tr>
      <td>Aftab</td>
      <td>aftab@example.com</td>
    </tr>
    <tr>
      <td>Rahim</td>
      <td>rahim@example.com</td>
    </tr>
  </table>

  <h2>Registration Form</h2>

  <form>
    <fieldset>
      <legend>Student Registration</legend>

      <label for="name">Name</label>
      <input type="text" id="name" placeholder="Enter your name" required>
      <br><br>

      <label for="email">Email</label>
      <input type="email" id="email" placeholder="Enter your email" required>
      <br><br>

      <label for="password">Password</label>
      <input type="password" id="password" required>
      <br><br>

      <p>Choose skills:</p>
      <input type="checkbox" id="html" name="skill">
      <label for="html">HTML</label>

      <input type="checkbox" id="css" name="skill">
      <label for="css">CSS</label>
      <br><br>

      <label for="city">City</label>
      <select id="city">
        <option>Dhaka</option>
        <option>Chattogram</option>
        <option>Khulna</option>
      </select>
      <br><br>

      <label for="message">Message</label>
      <textarea id="message" rows="4" cols="30"></textarea>
      <br><br>

      <button type="submit">Submit</button>
    </fieldset>
  </form>
</body>
</html>
````

---

# Chapter 4 — Semantic HTML and Page Structure

## 4.1 Why Semantic HTML?

Semantic HTML makes code more meaningful.

Instead of using only `<div>`, use:

* `<header>`
* `<nav>`
* `<main>`
* `<section>`
* `<article>`
* `<aside>`
* `<footer>`

Benefits:

* easier to read
* better for SEO
* better accessibility
* cleaner structure

---

## 4.2 Common Semantic Tags

### Header

````html
<header>
  <h1>My Website</h1>
</header>
````

### Navigation

````html
<nav>
  <a href="#">Home</a>
  <a href="#">About</a>
  <a href="#">Contact</a>
</nav>
````

### Main

````html
<main>
  <p>Main content goes here.</p>
</main>
````

### Section

````html
<section>
  <h2>Services</h2>
  <p>We provide web design services.</p>
</section>
````

### Article

````html
<article>
  <h2>Blog Title</h2>
  <p>This is a blog post.</p>
</article>
````

### Aside

````html
<aside>
  <p>This is sidebar content.</p>
</aside>
````

### Footer

````html
<footer>
  <p>&copy; 2026 My Website</p>
</footer>
````

---

## 4.3 `div` vs Semantic Tags

### Generic `div`

````html
<div>
  <h2>News</h2>
  <p>Latest updates...</p>
</div>
````

### Better semantic version

````html
<section>
  <h2>News</h2>
  <p>Latest updates...</p>
</section>
````

---

## 4.4 Full Page Structure Example

````html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Semantic Page</title>
</head>
<body>
  <header>
    <h1>My Portfolio</h1>
  </header>

  <nav>
    <a href="#">Home</a>
    <a href="#">Projects</a>
    <a href="#">Contact</a>
  </nav>

  <main>
    <section>
      <h2>About Me</h2>
      <p>I am learning frontend development.</p>
    </section>

    <section>
      <h2>Projects</h2>
      <article>
        <h3>Project 1</h3>
        <p>A simple HTML website.</p>
      </article>
      <article>
        <h3>Project 2</h3>
        <p>A responsive portfolio design.</p>
      </article>
    </section>
  </main>

  <aside>
    <p>Quick links and updates.</p>
  </aside>

  <footer>
    <p>&copy; 2026 My Portfolio</p>
  </footer>
</body>
</html>
````

---

# Chapter 5 — CSS Fundamentals

## 5.1 Ways to Use CSS

### Inline CSS

````html
<p style="color: red;">This is red text.</p>
````

### Internal CSS

````html
<style>
  p {
    color: blue;
  }
</style>
````

### External CSS

HTML:

````html
<link rel="stylesheet" href="style.css">
````

CSS file:

````css
p {
  color: green;
}
````

### Best practice

Use **external CSS** for real projects.

---

## 5.2 CSS Syntax

````css
selector {
  property: value;
}
````

Example:

````css
p {
  color: red;
  font-size: 18px;
}
````

---

## 5.3 Basic CSS Example

````html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>CSS Example</title>

  <style>
    h1 {
      color: navy;
    }

    p {
      color: gray;
      font-size: 18px;
    }
  </style>
</head>
<body>
  <h1>Welcome</h1>
  <p>This paragraph is styled with CSS.</p>
</body>
</html>
````

---

# Chapter 6 — CSS Selectors, Colors, Text, Box Model

## 6.1 Selectors

### Element selector

````css
p {
  color: blue;
}
````

### Class selector

````css
.note {
  color: green;
}
````

HTML:

````html
<p class="note">This is a note.</p>
````

### ID selector

````css
#title {
  color: red;
}
````

HTML:

````html
<h1 id="title">Main Title</h1>
````

### Universal selector

````css
* {
  margin: 0;
  padding: 0;
}
````

---

## 6.2 Colors in CSS

### Named color

````css
p {
  color: red;
}
````

### Hex color

````css
p {
  color: #ff0000;
}
````

### RGB

````css
p {
  color: rgb(255, 0, 0);
}
````

### Background color example

````css
body {
  background-color: #f4f4f4;
}
````

---

## 6.3 Text Styling

````css
h1 {
  color: #1a1a1a;
  font-size: 40px;
  font-family: Arial, sans-serif;
  text-align: center;
}
````

### Useful text properties

* `color`
* `font-size`
* `font-family`
* `font-weight`
* `text-align`
* `text-decoration`
* `text-transform`
* `line-height`
* `letter-spacing`

### Example

````css
p {
  font-size: 18px;
  line-height: 1.6;
  text-align: justify;
}
````

---

## 6.4 Box Model

Every element is like a box made of:

* content
* padding
* border
* margin

### Example

````css
.box {
  width: 300px;
  padding: 20px;
  border: 2px solid black;
  margin: 30px;
}
````

### Explanation

* `width` = content width
* `padding` = space inside border
* `border` = visible line around element
* `margin` = outer space

---

## 6.5 Border and Border Radius

````css
.card {
  border: 1px solid #ccc;
  border-radius: 10px;
}
````

---

## 6.6 Background

````css
.hero {
  background-color: lightblue;
}
````

### Background image

````css
.hero {
  background-image: url("bg.jpg");
  background-size: cover;
  background-position: center;
  background-repeat: no-repeat;
}
````

---

## 6.7 Chapter 6 Practice

````html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>CSS Practice</title>
  <style>
    body {
      background-color: #f7f7f7;
      font-family: Arial, sans-serif;
    }

    #title {
      text-align: center;
      color: #0f172a;
    }

    .card {
      width: 300px;
      padding: 20px;
      margin: 20px auto;
      background-color: white;
      border: 1px solid #ddd;
      border-radius: 12px;
    }

    .card p {
      color: #444;
      line-height: 1.6;
    }
  </style>
</head>
<body>
  <h1 id="title">CSS Card Example</h1>

  <div class="card">
    <h2>Card Title</h2>
    <p>
      This card uses background color, padding, border,
      margin, and border radius.
    </p>
  </div>
</body>
</html>
````

---

# Chapter 7 — Display, Position, Units, Flexbox

## 7.1 Display Types

### Block elements

Examples:

* `div`
* `p`
* `h1`
* `section`

They take full width.

### Inline elements

Examples:

* `a`
* `span`
* `img`

They only take required width.

### Inline-block

Behaves like inline, but accepts width and height.

````css
.box {
  display: inline-block;
  width: 100px;
  height: 100px;
}
````

---

## 7.2 Units

### Absolute unit

* `px`

### Relative units

* `%`
* `em`
* `rem`
* `vw`
* `vh`

### Example

````css
.container {
  width: 80%;
}

.title {
  font-size: 2rem;
}
````

---

## 7.3 Flexbox Basics

To use flexbox, apply `display: flex` to the parent.

````css
.container {
  display: flex;
}
````

---

## 7.4 Main Flexbox Properties

### `flex-direction`

````css
.container {
  display: flex;
  flex-direction: row;
}
````

Other values:

* `row`
* `column`
* `row-reverse`
* `column-reverse`

---

### `justify-content`

Controls horizontal alignment on main axis.

````css
.container {
  display: flex;
  justify-content: center;
}
````

Values:

* `flex-start`
* `center`
* `flex-end`
* `space-between`
* `space-around`
* `space-evenly`

---

### `align-items`

Controls vertical alignment on cross axis.

````css
.container {
  display: flex;
  align-items: center;
}
````

Values:

* `stretch`
* `flex-start`
* `center`
* `flex-end`

---

### `gap`

Adds spacing between items.

````css
.container {
  display: flex;
  gap: 20px;
}
````

---

### `flex-wrap`

Allows items to move to next line.

````css
.container {
  display: flex;
  flex-wrap: wrap;
}
````

---

## 7.5 Flexbox Example 1 — Horizontal Cards

````html
<!DOCTYPE html>
<html lang="en">
<head>
  <style>
    .container {
      display: flex;
      gap: 20px;
    }

    .card {
      background: lightgray;
      padding: 20px;
      width: 150px;
    }
  </style>
</head>
<body>
  <div class="container">
    <div class="card">Card 1</div>
    <div class="card">Card 2</div>
    <div class="card">Card 3</div>
  </div>
</body>
</html>
````

---

## 7.6 Flexbox Example 2 — Centering

````css
.wrapper {
  display: flex;
  justify-content: center;
  align-items: center;
  height: 100vh;
}
````

````html
<div class="wrapper">
  <div class="box">Centered Box</div>
</div>
````

---

## 7.7 Flexbox Example 3 — Navigation Bar

````html
<nav class="navbar">
  <h2>Logo</h2>
  <div class="links">
    <a href="#">Home</a>
    <a href="#">About</a>
    <a href="#">Contact</a>
  </div>
</nav>
````

````css
.navbar {
  display: flex;
  justify-content: space-between;
  align-items: center;
  padding: 20px;
}
````

---

# Chapter 8 — Responsive Web Design and Media Queries

## 8.1 What is Responsive Design?

Responsive design means a website adjusts nicely for:

* mobile
* tablet
* laptop
* desktop

---

## 8.2 Why Responsive Design Matters

Without responsiveness:

* text may overflow
* cards may break layout
* images may become too large
* mobile users suffer

---

## 8.3 Responsive Images

````css
img {
  max-width: 100%;
  height: auto;
}
````

This keeps images inside container width.

---

## 8.4 Media Queries

Media queries apply styles only at certain screen sizes.

### Example

````css
@media screen and (max-width: 768px) {
  body {
    background-color: lightyellow;
  }
}
````

---

## 8.5 Flex Layout Responsive Example

### Normal layout

````css
.cards {
  display: flex;
  gap: 20px;
}
````

### Mobile layout

````css
@media screen and (max-width: 768px) {
  .cards {
    flex-direction: column;
  }
}
````

---

## 8.6 Responsive Navbar Example

````html
<nav class="navbar">
  <h1>Logo</h1>
  <div class="menu">
    <a href="#">Home</a>
    <a href="#">About</a>
    <a href="#">Contact</a>
  </div>
</nav>
````

````css
.navbar {
  display: flex;
  justify-content: space-between;
  align-items: center;
  padding: 20px;
}

.menu {
  display: flex;
  gap: 16px;
}

@media screen and (max-width: 600px) {
  .navbar {
    flex-direction: column;
    gap: 15px;
  }

  .menu {
    flex-direction: column;
    align-items: center;
  }
}
````

---

## 8.7 Responsive Card Grid Example

````html
<section class="grid">
  <div class="card">Card 1</div>
  <div class="card">Card 2</div>
  <div class="card">Card 3</div>
  <div class="card">Card 4</div>
</section>
````

````css
.grid {
  display: flex;
  flex-wrap: wrap;
  gap: 20px;
}

.card {
  width: 220px;
  padding: 20px;
  background: #eee;
}

@media screen and (max-width: 768px) {
  .card {
    width: 100%;
  }
}
````

---

# Chapter 9 — Final Mini Projects

## 9.1 Final Project 1 — Simple Personal Page

````html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Personal Page</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      margin: 0;
      padding: 0;
      background: #f5f5f5;
    }

    header {
      background: #1e293b;
      color: white;
      padding: 20px;
      text-align: center;
    }

    .container {
      width: 90%;
      max-width: 1000px;
      margin: 30px auto;
    }

    .card {
      background: white;
      padding: 20px;
      border-radius: 12px;
      margin-bottom: 20px;
    }

    img {
      max-width: 100%;
      height: auto;
      border-radius: 10px;
    }
  </style>
</head>
<body>
  <header>
    <h1>Aftab's Personal Page</h1>
    <p>HTML + CSS Practice</p>
  </header>

  <div class="container">
    <div class="card">
      <h2>About Me</h2>
      <p>I am learning web development step by step.</p>
    </div>

    <div class="card">
      <h2>My Skills</h2>
      <ul>
        <li>HTML</li>
        <li>CSS</li>
        <li>Responsive Design</li>
      </ul>
    </div>

    <div class="card">
      <h2>Contact</h2>
      <p>Email: aftab@example.com</p>
    </div>
  </div>
</body>
</html>
````

---

## 9.2 Final Project 2 — Responsive Portfolio Layout

````html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Responsive Portfolio</title>
  <style>
    * {
      margin: 0;
      padding: 0;
      box-sizing: border-box;
    }

    body {
      font-family: Arial, sans-serif;
      background: #f8fafc;
      color: #1f2937;
    }

    header {
      background: #0f172a;
      color: white;
      padding: 20px 40px;
    }

    .navbar {
      display: flex;
      justify-content: space-between;
      align-items: center;
    }

    .menu {
      display: flex;
      gap: 20px;
    }

    .menu a {
      color: white;
      text-decoration: none;
    }

    .hero {
      display: flex;
      justify-content: space-between;
      align-items: center;
      gap: 30px;
      padding: 50px 40px;
    }

    .hero-text,
    .hero-image {
      flex: 1;
    }

    .hero-image img {
      max-width: 100%;
      border-radius: 16px;
    }

    .projects {
      display: flex;
      flex-wrap: wrap;
      gap: 20px;
      padding: 40px;
    }

    .project-card {
      background: white;
      border-radius: 14px;
      padding: 20px;
      width: calc(33.333% - 20px);
      box-shadow: 0 2px 10px rgba(0,0,0,0.08);
    }

    footer {
      text-align: center;
      padding: 20px;
      background: #e2e8f0;
    }

    @media screen and (max-width: 900px) {
      .hero {
        flex-direction: column;
      }

      .project-card {
        width: calc(50% - 20px);
      }
    }

    @media screen and (max-width: 600px) {
      .navbar {
        flex-direction: column;
        gap: 15px;
      }

      .menu {
        flex-direction: column;
        align-items: center;
      }

      .project-card {
        width: 100%;
      }
    }
  </style>
</head>
<body>
  <header>
    <nav class="navbar">
      <h1>My Portfolio</h1>
      <div class="menu">
        <a href="#">Home</a>
        <a href="#">Projects</a>
        <a href="#">Contact</a>
      </div>
    </nav>
  </header>

  <section class="hero">
    <div class="hero-text">
      <h2>Hello, I am a Web Learner</h2>
      <p>
        I am practicing HTML, CSS, Flexbox, and responsive design
        to build modern websites.
      </p>
    </div>
    <div class="hero-image">
      <img src="profile.jpg" alt="Profile image">
    </div>
  </section>

  <section class="projects">
    <div class="project-card">
      <h3>Project One</h3>
      <p>A simple semantic HTML website.</p>
    </div>
    <div class="project-card">
      <h3>Project Two</h3>
      <p>A flexbox card layout.</p>
    </div>
    <div class="project-card">
      <h3>Project Three</h3>
      <p>A responsive landing page.</p>
    </div>
  </section>

  <footer>
    <p>&copy; 2026 My Portfolio</p>
  </footer>
</body>
</html>
````

---

# Chapter 10 — Quick Revision Cheat Sheet

## HTML Essentials

````text
<!DOCTYPE html>  -> HTML5 declaration
<html>           -> root element
<head>           -> metadata
<title>          -> page title
<body>           -> visible content
<h1> to <h6>     -> headings
<p>              -> paragraph
<a>              -> link
<img>            -> image
<ul>, <ol>, <li> -> lists
<table>          -> table
<form>           -> form
<input>          -> user input
<textarea>       -> multi-line input
<select>         -> dropdown
<iframe>         -> embedded page/media
<header>         -> top section
<nav>            -> navigation
<section>        -> content section
<footer>         -> bottom section
````

## CSS Essentials

````text
selector { property: value; }

color
background-color
font-size
font-family
width
height
margin
padding
border
border-radius
display
flex-direction
justify-content
align-items
gap
max-width
````

## Flexbox Essentials

````css
.container {
  display: flex;
  flex-direction: row;
  justify-content: center;
  align-items: center;
  gap: 20px;
}
````

## Responsive Essentials

````css
img {
  max-width: 100%;
  height: auto;
}

@media screen and (max-width: 768px) {
  .container {
    flex-direction: column;
  }
}
````

---

# Final Advice

1. First learn structure with HTML.
2. Then learn style with CSS.
3. Then learn layout with Flexbox.
4. Then learn responsiveness with media queries.
5. Practice by making:

   * personal page
   * blog layout
   * registration form
   * portfolio site
   * product card section

---

# Practice Tasks

## Task 1

Create a page with:

* one heading
* two paragraphs
* one image
* one link

## Task 2

Create:

* unordered list of 5 fruits
* ordered list of 5 study steps

## Task 3

Make a registration form with:

* name
* email
* password
* city dropdown
* submit button

## Task 4

Create a card using CSS with:

* padding
* border
* background color
* margin
* rounded corner

## Task 5

Create a flexbox layout with 3 cards in a row.

## Task 6

Make the 3 cards stack vertically on mobile using media query.

---

# End of Handbook
