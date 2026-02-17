# GitHub OAuth UI Components - Visual Guide

## 1. Login Dialog

### When Shown
- Appears when user clicks "Login to GitHub" button
- Displays: Loading spinner + "Logging you in!" text
- Blocks all page interactions (semi-transparent dark overlay)
- Cannot close except by completing login or browser refresh

### Visual Appearance
```
┌─────────────────────────────────────────────┐
│                                             │
│          [Loading Spinner]                  │
│                                             │
│           Logging you in!                   │
│                                             │
│                                             │
└─────────────────────────────────────────────┘
  (Semi-transparent dark overlay with blur)
```

### CSS Class
`#login-dialog` - Main dialog container
`.login-spinner` - Animated spinner (rotates)
`.login-text` - "Logging you in!" text

### Responsive Behavior
- **Desktop**: Center of screen, large spinner (60px)
- **Tablet**: Same as desktop
- **Mobile**: Adjusted text size, smaller spinner (50px)

---

## 2. User Profile Section (Navbar)

### When Shown
- After successful login
- Replaces "Login to GitHub" button
- Located in top-right of navbar

### Visual Appearance
```
Desktop:
┌──────────────────────────┐
│ [Avatar] username [Logout] │
└──────────────────────────┘
  (with purple/pink border, glassmorphic)

Mobile:
┌──────────────────┐
│ [Avatar] [Logout] │
└──────────────────┘
  (username hidden on small screens)
```

### Components

#### Avatar
- Circular image (32px desktop, 28px mobile)
- Border: 2px solid purple/pink
- Hover effect: Scales up slightly
- Source: GitHub user avatar URL

#### Username
- Text next to avatar (desktop only)
- Font: 0.9rem, weight 500
- Color: White (#FFFFFF)
- Hidden on mobile/tablet

#### Logout Button
- SVG icon (exit/logout symbol)
- Color: Pink (#FF6A84)
- Hover: Lighter pink (#FF8FA1) + scale 1.1
- Tooltip: "Logout"

#### Container Styling
- Background: `rgba(111, 76, 255, 0.1)` (semi-transparent purple)
- Border: 1px solid `rgba(111, 76, 255, 0.3)`
- Border-radius: 50px (pill shape)
- Padding: 0.5rem 1rem (desktop), 0.4rem 0.8rem (mobile)
- Hover: Slightly brighter background

---

## 3. Navigation Bar Integration

### Before Login
```
[LoudWave] [Home] [About Us] [Downloads] [Github] .......... [Login to GitHub]
                                                       └─ desktop only
```

### After Login
```
[LoudWave] [Home] [About Us] [Downloads] [Github] .......... [Avatar] username [✕]
                                                       └─ desktop only
```

### CSS Classes
- `.nav-right` - Container for login button or user profile
- `.desktop-only` - Hides on mobile, shows on desktop
- `.mobile-only` - Shows on mobile, hides on desktop
- `.user-profile` - The entire user profile section
- `.user-avatar` - The circular avatar image
- `.user-name` - Username text
- `.logout-btn` - Logout button

---

## 4. Dialog Animation

### Loading Spinner Animation
```javascript
@keyframes login-spin {
    from {
        transform: rotate(0deg);
    }
    to {
        transform: rotate(360deg);
    }
}
// Duration: 1s
// Iteration: infinite
// Timing: linear (constant rotation)
```

### Avatar Hover Animation
- Transform: scale(1.05)
- Duration: 0.2s ease
- Makes avatar slightly larger on hover

### Logout Button Hover Animation
- Transform: scale(1.1)
- Duration: 0.2s ease
- Color change: #FF6A84 → #FF8FA1

---

## 5. Responsive Breakpoints

### Desktop (1024px+)
```css
- Avatar: 32px
- Username: visible (0.9rem)
- Container padding: 0.5rem 1rem
- Gap between items: 0.75rem
- Login button: full size
```

### Tablet (768px - 1023px)
```css
- Same as desktop
- Login button may stack on new line if space tight
```

### Mobile (640px - 767px)
```css
- Avatar: 28px
- Username: visible but smaller
- Container padding: 0.4rem 0.8rem
- Gap: 0.5rem
```

### Small Mobile (480px and below)
```css
- Avatar: 28px
- Username: HIDDEN
- Only avatar + logout button visible
- Login spinner: 50px (instead of 60px)
- Dialog text: 1.2rem (instead of 1.5rem)
```

---

## 6. Color Scheme

### Dialog
- Overlay background: `rgba(10, 10, 15, 0.95)` (very dark with high opacity)
- Overlay blur: 10px
- Spinner border (inactive): `rgba(111, 76, 255, 0.2)` (dim purple)
- Spinner border (active): `#6F4CFF` (bright purple)
- Text color: `#FFFFFF` (white)

### User Profile
- Container background: `rgba(111, 76, 255, 0.1)` (very light purple)
- Container border: `rgba(111, 76, 255, 0.3)` (light purple border)
- Container hover: `rgba(111, 76, 255, 0.15)` (slightly brighter)
- Avatar border: `rgba(111, 76, 255, 0.5)` (medium purple)
- Text: `#FFFFFF` (white)
- Logout icon: `#FF6A84` (pink)

---

## 7. HTML Structure

### Dialog HTML
```html
<div id="login-dialog" class="login-dialog">
    <div class="login-dialog-content">
        <div class="login-spinner"></div>
        <p class="login-text">Logging you in!</p>
    </div>
</div>
```

### User Profile HTML (Generated)
```html
<div class="user-profile">
    <img src="avatar-url" alt="username" class="user-avatar" title="username">
    <span class="user-name">username</span>
    <button onclick="logoutUser()" class="logout-btn" title="Logout">
        <svg>...</svg>
    </button>
</div>
```

---

## 8. JavaScript State Management

### Dialog States

```javascript
// Show dialog
showLoginDialog()
// Sets: #login-dialog { display: flex; }

// Hide dialog
hideLoginDialog()
// Sets: #login-dialog { display: none; }
```

### User Profile States

```javascript
// After successful login
updateUIAfterLogin(userData)
// 1. Hides "Login to GitHub" button
// 2. Shows user profile section with avatar, name, logout button
// 3. Hides login dialog

// After logout
updateUIAfterLogout()
// 1. Shows "Login to GitHub" button again
// 2. Hides user profile section
// 3. Clears localStorage
// 4. Reloads page
```

---

## 9. CSS Variable Mapping

If you want to customize colors, here are the key values:

```css
/* Dialog */
--dialog-bg: rgba(10, 10, 15, 0.95);
--dialog-blur: 10px;
--spinner-inactive: rgba(111, 76, 255, 0.2);
--spinner-active: #6F4CFF;
--spinner-size: 60px; /* 50px on mobile */

/* Profile */
--profile-bg: rgba(111, 76, 255, 0.1);
--profile-border: rgba(111, 76, 255, 0.3);
--profile-hover-bg: rgba(111, 76, 255, 0.15);
--avatar-size: 32px; /* 28px on mobile */
--avatar-border: rgba(111, 76, 255, 0.5);
--logout-color: #FF6A84;
--logout-hover: #FF8FA1;
```

---

## 10. Browser Compatibility

### Supported Features
- ✅ Modern browsers (Chrome, Firefox, Safari, Edge)
- ✅ CSS Grid & Flexbox
- ✅ CSS Backdrop Filter (with -webkit- prefix)
- ✅ CSS Animations
- ✅ Fetch API
- ✅ LocalStorage
- ✅ Template Literals (ES6)

### Required Browser Features
- CSS Backdrop Filter (for blur effect)
- Async/Await (for API calls)
- Fetch API (for HTTP requests)
- LocalStorage API (for token storage)

---

## 11. Accessibility

### Keyboard Navigation
- Tab through navbar items including user profile
- Focus indicator on logout button
- Logout button is clickable with Enter key

### Screen Readers
- Avatar has `alt` attribute with username
- Buttons have `title` attributes
- Semantic HTML structure

### Color Contrast
- White text on dark background: High contrast ✅
- Purple elements: Sufficient contrast ✅
- Pink logout button: Sufficient contrast ✅

---

## 12. Custom Styling (Optional)

To customize the dialog appearance, edit in `styles.css`:

```css
/* Change dialog overlay opacity */
#login-dialog {
    background: rgba(10, 10, 15, 0.9); /* 0.9 instead of 0.95 */
}

/* Change spinner color */
.login-spinner {
    border-top: 4px solid #FF6A84; /* Pink instead of purple */
}

/* Change spinner size */
.login-spinner {
    width: 80px;
    height: 80px;
}

/* Change profile background */
.user-profile {
    background: rgba(255, 106, 132, 0.1); /* Pink tint instead of purple */
}
```

---

## 13. Testing Checklist

- [ ] Dialog appears when clicking "Login to GitHub"
- [ ] Dialog has spinner animation (rotating)
- [ ] Dialog text says "Logging you in!"
- [ ] Dialog blocks all page interactions (can't click outside)
- [ ] Dialog disappears after login completes
- [ ] User avatar displays with correct image
- [ ] Username displays correctly (desktop)
- [ ] Username hidden on mobile
- [ ] Logout button visible with icon
- [ ] Logout button clickable
- [ ] Avatar has hover effect (scales up)
- [ ] Logout button has hover effect (changes color + scales)
- [ ] Responsive on all screen sizes
- [ ] Colors match design system

