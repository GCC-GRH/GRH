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

    // Note: Mobile menu functionality is now handled by toggleMobileMenu() in github-auth.js
    // The old menu toggle code has been removed to prevent conflicts with the new drawer menu

    // About us team modal interactions
    const teamCards = document.querySelectorAll('.team-card');
    const memberModal = document.querySelector('.member-modal');
    const memberName = document.querySelector('.member-name');
    const memberRole = document.querySelector('.member-role');
    const memberBio = document.querySelector('.member-bio');
    const memberAvatar = document.querySelector('.member-avatar');
    const closeMember = document.querySelector('.close-member');

    teamCards.forEach(card => {
        card.addEventListener('click', () => {
            const name = card.getAttribute('data-name');
            const role = card.getAttribute('data-role');
            const bio = card.getAttribute('data-bio');

            memberName.textContent = name;
            memberRole.textContent = role;
            memberBio.textContent = bio;
            // Simple avatar placeholder color change based on name hash
            const colorHash = name.split('').reduce((acc, ch) => acc + ch.charCodeAt(0), 0);
            const hue = colorHash % 360;
            memberAvatar.style.background = `linear-gradient(135deg, hsl(${hue} 60% 60% / 0.12), rgba(255,255,255,0.06))`;

            memberModal.setAttribute('aria-hidden', 'false');
            document.body.style.overflow = 'hidden';
        });
    });

    function closeModal() {
        memberModal.setAttribute('aria-hidden', 'true');
        document.body.style.overflow = 'auto';
    }

    closeMember.addEventListener('click', closeModal);
    memberModal.addEventListener('click', (e) => {
        if (e.target === memberModal) closeModal();
    });
});
