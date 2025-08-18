document.addEventListener('DOMContentLoaded', () => {
    // Original typing animation
    const typingElement = document.querySelector('.typing-text');
    const cursor = document.querySelector('.cursor');
    const text = "Desktop On The Cloud";
    let charIndex = 0;
    let typingDelay = 100; // Delay between each character when typing
    let displayTime = 2000; // Display complete text for 2 seconds
    let deletingDelay = 75; // Delay between each character when deleting
    let isDeleting = false;
    let currentText = '';
    
    // Apply styles
    typingElement.style.setProperty('opacity', '1', 'important');
    typingElement.style.setProperty('visibility', 'visible', 'important');
    typingElement.style.setProperty('color', 'white', 'important');
    typingElement.style.setProperty('-webkit-text-fill-color', 'white', 'important');
    typingElement.style.setProperty('background', 'none', 'important');
    typingElement.style.setProperty('text-align', 'center', 'important');
    typingElement.style.setProperty('display', 'inline-block', 'important');
    typingElement.style.setProperty('white-space', 'nowrap', 'important');
    
    // Container styling to ensure center alignment
    const parentContainer = typingElement.closest('.typing-container');
    parentContainer.style.setProperty('display', 'flex', 'important');
    parentContainer.style.setProperty('justify-content', 'center', 'important');
    parentContainer.style.setProperty('align-items', 'center', 'important');
    parentContainer.style.setProperty('text-align', 'center', 'important');
    parentContainer.style.setProperty('width', '100%', 'important');
    parentContainer.style.setProperty('overflow', 'visible', 'important');
    
    // Original typing function
    function type() {
        if (!isDeleting && charIndex <= text.length) {
            // Typing
            currentText = text.substring(0, charIndex);
            typingElement.textContent = currentText;
            charIndex++;
            
            if (charIndex > text.length) {
                // Finished typing
                setTimeout(() => {
                    isDeleting = true;
                    type();
                }, displayTime);
            } else {
                setTimeout(type, typingDelay);
            }
        } else if (isDeleting && charIndex > 0) {
            // Deleting
            charIndex--;
            currentText = text.substring(0, charIndex);
            typingElement.textContent = currentText;
            setTimeout(type, deletingDelay);
        } else {
            // Reset
            isDeleting = false;
            charIndex = 0;
            setTimeout(type, typingDelay);
        }
    }
    
    // Start the typing animation
    setTimeout(() => {
        type();
    }, 500);
    
    // Cursor blinking
    setInterval(() => {
        cursor.style.opacity = cursor.style.opacity === '0' ? '1' : '0';
    }, 500);

    // Mobile menu functionality
    const mobileNavToggle = document.querySelector('.mobile-nav-toggle');
    const navLinks = document.querySelector('.nav-links');

    mobileNavToggle.addEventListener('click', () => {
        const isOpened = mobileNavToggle.getAttribute('aria-expanded') === 'true';
        
        mobileNavToggle.setAttribute('aria-expanded', !isOpened);
        mobileNavToggle.classList.toggle('active');
        navLinks.classList.toggle('active');
        
        // Prevent body scrolling when menu is open
        document.body.style.overflow = isOpened ? 'auto' : 'hidden';
    });

    // Close mobile menu when clicking outside
    document.addEventListener('click', (e) => {
        if (!navLinks.contains(e.target) && !mobileNavToggle.contains(e.target) && navLinks.classList.contains('active')) {
            navLinks.classList.remove('active');
            mobileNavToggle.classList.remove('active');
            mobileNavToggle.setAttribute('aria-expanded', 'false');
            document.body.style.overflow = 'auto';
        }
    });

    // Close mobile menu when window is resized to desktop size
    window.addEventListener('resize', () => {
        if (window.innerWidth > 768 && navLinks.classList.contains('active')) {
            navLinks.classList.remove('active');
            mobileNavToggle.classList.remove('active');
            mobileNavToggle.setAttribute('aria-expanded', 'false');
            document.body.style.overflow = 'auto';
        }
    });
});
