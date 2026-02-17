// Server data - central source of truth
const servers = [
    {
        id: 'windows11',
        name: 'Main Server',
        os: 'Windows 11 Pro',
        status: 'online',
        icon: '<path d="M0 3.449L9.75 2.1v9.451H0m10.949-9.602L24 0v11.4H10.949M0 12.6h9.75v9.451L0 20.699M10.949 12.6H24V24l-12.9-1.801"/>',
        cpu: 45,
        ram: 62,
        network: '120ms',
        connections: 156,
        workflowUsed: 2.5,
        workflowTotal: 10
    }
];

// Dummy processes data
const dummyProcesses = [
    { id: 'proc1', name: 'Chrome.exe', ram: 2.4, selected: false },
    { id: 'proc2', name: 'Discord.exe', ram: 1.8, selected: false },
    { id: 'proc3', name: 'VSCode.exe', ram: 1.2, selected: false },
    { id: 'proc4', name: 'Spotify.exe', ram: 0.8, selected: false },
    { id: 'proc5', name: 'explorer.exe', ram: 0.5, selected: false },
    { id: 'proc6', name: 'Steam.exe', ram: 2.1, selected: false },
    { id: 'proc7', name: 'Photoshop.exe', ram: 3.2, selected: false },
    { id: 'proc8', name: 'node.exe', ram: 0.6, selected: false },
    { id: 'proc9', name: 'Teams.exe', ram: 1.4, selected: false },
    { id: 'proc10', name: 'WindowsTerminal.exe', ram: 0.4, selected: false }
];

let currentProcesses = [...dummyProcesses];

// Update PC grid with available servers
function updatePCGrid() {
    const pcGrid = document.getElementById('pc-grid');
    const availableCount = servers.filter(s => s.status === 'online').length;
    
    // Update badge
    document.querySelector('#pc-section .status-badge').textContent = `${availableCount} Available`;
    
    // Clear and rebuild grid
    pcGrid.innerHTML = '';
    servers.forEach(server => {
        const gridItem = document.createElement('div');
        gridItem.className = 'grid-item';
        gridItem.onclick = () => connectToServer(server.id);
        gridItem.innerHTML = `
            <div class="os-icon">
                <svg viewBox="0 0 24 24">
                    ${server.icon}
                </svg>
            </div>
            <div class="server-name">${server.name}</div>
            <div class="server-os">${server.os}</div>
        `;
        pcGrid.appendChild(gridItem);
    });
}

// Update Server list
function updateServerList() {
    const serverList = document.getElementById('server-list');
    
    // Clear existing server cards
    serverList.innerHTML = '';
    
    // Add all server cards
    servers.forEach(server => {
        const card = document.createElement('div');
        card.className = 'card server-card clickable';
        card.onclick = () => expandServer(server.id);
        card.innerHTML = `
            <div class="server-header">
                <div class="os-icon">
                    <svg viewBox="0 0 24 24">
                        ${server.icon}
                    </svg>
                </div>
                <div class="server-info">
                    <div class="server-name">${server.name}</div>
                    <div class="server-os">${server.os}</div>
                </div>
                <svg class="chevron-icon" viewBox="0 0 24 24" fill="none" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
                    <polyline points="9 18 15 12 9 6"></polyline>
                </svg>
            </div>
            <span class="status-badge">${server.status === 'online' ? 'Online' : 'Offline'}</span>
        `;
        serverList.appendChild(card);
    });
    
    // Add the "Add more server" button
    const addButton = document.createElement('div');
    addButton.className = 'card add-server clickable';
    addButton.onclick = addNewServer;
    addButton.innerHTML = `
        <svg class="add-icon" viewBox="0 0 24 24" fill="none" stroke-linecap="round" stroke-linejoin="round">
            <line x1="12" y1="5" x2="12" y2="19"></line>
            <line x1="5" y1="12" x2="19" y2="12"></line>
        </svg>
        <span>Add more server</span>
    `;
    serverList.appendChild(addButton);
}

// Initialize on page load
updatePCGrid();
updateServerList();

const navItems = document.querySelectorAll('.nav-item');
const sections = document.querySelectorAll('.section');

navItems.forEach(item => {
    item.addEventListener('click', () => {
        const sectionId = item.getAttribute('data-section');
        
        // Remove active class from all nav items
        navItems.forEach(nav => nav.classList.remove('active'));
        
        // Add active class to clicked item
        item.classList.add('active');
        
        // Hide all sections
        sections.forEach(section => section.classList.remove('active'));
        
        // Show selected section
        document.getElementById(sectionId).classList.add('active');

        // Close any expanded server details when switching sections
        closeServerDetail();

        // Update liquid indicator
        updateNavIndicator();

        // Haptic feedback for mobile devices
        if (navigator.vibrate) {
            navigator.vibrate(10);
        }
    });
});

// Liquid Navigation Indicator
function updateNavIndicator() {
    const activeItem = document.querySelector('.nav-item.active');
    const indicator = document.querySelector('.nav-indicator');
    
    if (activeItem && indicator) {
        // Fixed size for the circular droplet
        const size = 51; 
        
        const rect = activeItem.getBoundingClientRect();
        const parentRect = activeItem.parentElement.getBoundingClientRect();
        
        // Calculate center position relative to the parent (nav)
        const centerX = (rect.left - parentRect.left) + (rect.width / 2);
        const centerY = (rect.top - parentRect.top) + (rect.height / 2);
        
        const left = centerX - (size / 2);
        const top = centerY - (size / 2);
        
        indicator.style.width = `${size}px`;
        indicator.style.height = `${size}px`;
        indicator.style.transform = `translate(${left}px, ${top}px)`;
    }
}

// Initialize indicator
window.addEventListener('load', updateNavIndicator);
window.addEventListener('resize', updateNavIndicator);
// Also call immediately in case load already happened
updateNavIndicator();

// Connect to server from PC page
function connectToServer(serverId) {
    if (navigator.vibrate) {
        navigator.vibrate(10);
    }
    alert(`Connecting to ${serverId}... You can implement your connection logic here!`);
}

// Server expand/collapse functionality
function expandServer(serverId) {
    const server = servers.find(s => s.id === serverId);
    if (!server) return;

    // Hide header
    document.querySelector('.header').style.display = 'none';

    // Update detail view with server data
    document.getElementById('server-detail').innerHTML = `
        <div class="back-button" onclick="closeServerDetail()">
            <svg viewBox="0 0 24 24" fill="none" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
                <polyline points="15 18 9 12 15 6"></polyline>
            </svg>
            <span>Back</span>
        </div>

        <div class="card">
            <div class="server-header">
                <div class="os-icon">
                    <svg viewBox="0 0 24 24">
                        ${server.icon}
                    </svg>
                </div>
                <div class="server-info">
                    <div class="server-name">${server.name}</div>
                    <div class="server-os">${server.os}</div>
                </div>
            </div>
            <span class="status-badge">${server.status === 'online' ? 'Online' : 'Offline'}</span>

            <div class="status-grid">
                <div class="status-item">
                    <div class="status-label">CPU Usage</div>
                    <div class="status-value">${server.cpu}%</div>
                    <div class="progress-bar">
                        <div class="progress-fill" style="width: ${server.cpu}%"></div>
                    </div>
                </div>
                <div class="status-item">
                    <div class="status-label">RAM Usage</div>
                    <div class="status-value">${server.ram}%</div>
                    <div class="progress-bar">
                        <div class="progress-fill" style="width: ${server.ram}%"></div>
                    </div>
                </div>
                <div class="status-item">
                    <div class="status-label">Network</div>
                    <div class="status-value">${server.network}</div>
                </div>
                <div class="status-item">
                    <div class="status-label">Connections</div>
                    <div class="status-value">${server.connections}</div>
                </div>
            </div>
        </div>

        <div class="card">
            <div class="detail-section">
                <h4>Workflow Time</h4>
                <div class="status-item">
                    <div class="status-label">Used / Total</div>
                    <div class="status-value">${server.workflowUsed}h / ${server.workflowTotal}h</div>
                    <div class="progress-bar">
                        <div class="progress-fill" style="width: ${(server.workflowUsed / server.workflowTotal) * 100}%"></div>
                    </div>
                </div>
            </div>

            <div class="action-buttons">
                <button class="action-btn task-manager" onclick="event.stopPropagation(); openTaskManager('${server.id}')">
                    <svg viewBox="0 0 24 24" fill="none" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
                        <rect x="3" y="3" width="18" height="18" rx="2" ry="2"></rect>
                        <line x1="9" y1="3" x2="9" y2="21"></line>
                    </svg>
                    <span>Task Manager</span>
                </button>
                <button class="action-btn terminate" onclick="event.stopPropagation(); openTerminateDialog('${server.id}')">
                    <svg viewBox="0 0 24 24" fill="none" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
                        <path d="M18.36 6.64a9 9 0 1 1-12.73 0"></path>
                        <line x1="12" y1="2" x2="12" y2="12"></line>
                    </svg>
                    <span>Terminate</span>
                </button>
            </div>
        </div>
    `;

    document.getElementById('server-list').style.display = 'none';
    document.getElementById('server-detail').classList.add('active');
    
    if (navigator.vibrate) {
        navigator.vibrate(10);
    }
}

function closeServerDetail() {
    document.getElementById('server-list').style.display = 'block';
    document.getElementById('server-detail').classList.remove('active');
    
    // Show header
    document.querySelector('.header').style.display = 'flex';
    
    if (navigator.vibrate) {
        navigator.vibrate(10);
    }
}

function addNewServer() {
    if (navigator.vibrate) {
        navigator.vibrate(10);
    }
    
    alert('Add new server functionality - you can implement this!');
}

// Task Manager function
window.openTaskManager = function(serverId) {
    if (navigator.vibrate) {
        navigator.vibrate(10);
    }
    
    // Reset processes
    currentProcesses = [...dummyProcesses];
    renderProcesses();
    updateRamUsage();
    
    document.getElementById('taskManagerDialog').classList.add('active');
}

window.closeTaskManager = function() {
    document.getElementById('taskManagerDialog').classList.remove('active');
    if (navigator.vibrate) {
        navigator.vibrate(10);
    }
}

function renderProcesses() {
    const processesList = document.getElementById('processesList');
    processesList.innerHTML = '';
    
    currentProcesses.forEach(process => {
        const processItem = document.createElement('div');
        processItem.className = `process-item ${process.selected ? 'selected' : ''}`;
        processItem.onclick = () => toggleProcessSelection(process.id);
        
        processItem.innerHTML = `
            <div class="process-checkbox">
                <svg viewBox="0 0 24 24" fill="none" stroke-width="3" stroke-linecap="round" stroke-linejoin="round">
                    <polyline points="20 6 9 17 4 12"></polyline>
                </svg>
            </div>
            <div class="process-info">
                <div class="process-name">${process.name}</div>
                <div class="process-ram">${process.ram} GB RAM</div>
            </div>
        `;
        
        processesList.appendChild(processItem);
    });
    
    updateEndButton();
}

function toggleProcessSelection(processId) {
    const process = currentProcesses.find(p => p.id === processId);
    if (process) {
        process.selected = !process.selected;
        renderProcesses();
        
        if (navigator.vibrate) {
            navigator.vibrate(5);
        }
    }
}

function updateEndButton() {
    const selectedCount = currentProcesses.filter(p => p.selected).length;
    const endBtn = document.getElementById('endProcessBtn');
    
    if (selectedCount > 0) {
        endBtn.disabled = false;
        endBtn.innerHTML = `
            <svg viewBox="0 0 24 24" fill="none" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
                <circle cx="12" cy="12" r="10"></circle>
                <line x1="15" y1="9" x2="9" y2="15"></line>
                <line x1="9" y1="9" x2="15" y2="15"></line>
            </svg>
            <span>End ${selectedCount} Process${selectedCount > 1 ? 'es' : ''}</span>
        `;
    } else {
        endBtn.disabled = true;
        endBtn.innerHTML = `
            <svg viewBox="0 0 24 24" fill="none" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
                <circle cx="12" cy="12" r="10"></circle>
                <line x1="15" y1="9" x2="9" y2="15"></line>
                <line x1="9" y1="9" x2="15" y2="15"></line>
            </svg>
            <span>End Selected Processes</span>
        `;
    }
}

function updateRamUsage() {
    const totalRam = 16;
    const usedRam = currentProcesses.reduce((sum, p) => sum + p.ram, 0);
    const percentage = (usedRam / totalRam) * 100;
    
    document.getElementById('totalRamUsage').textContent = `${usedRam.toFixed(1)} GB / ${totalRam} GB`;
    document.getElementById('totalRamBar').style.width = `${percentage}%`;
}

window.endSelectedProcesses = function() {
    currentProcesses = currentProcesses.filter(p => !p.selected);
    renderProcesses();
    updateRamUsage();
    
    if (navigator.vibrate) {
        navigator.vibrate(20);
    }
}

// Close task manager when clicking outside
document.getElementById('taskManagerDialog').addEventListener('click', function(e) {
    if (e.target === this) {
        closeTaskManager();
    }
});

// Terminate Dialog functions
let currentServerToTerminate = null;

window.openTerminateDialog = function(serverId) {
    currentServerToTerminate = serverId;
    document.getElementById('terminateDialog').classList.add('active');
    if (navigator.vibrate) {
        navigator.vibrate(10);
    }
}

window.closeTerminateDialog = function() {
    document.getElementById('terminateDialog').classList.remove('active');
    currentServerToTerminate = null;
    if (navigator.vibrate) {
        navigator.vibrate(10);
    }
}

window.confirmTerminate = function() {
    if (currentServerToTerminate) {
        // Find and remove the server
        const serverIndex = servers.findIndex(s => s.id === currentServerToTerminate);
        if (serverIndex !== -1) {
            servers.splice(serverIndex, 1);
            updatePCGrid();
            updateServerList();
            closeServerDetail();
        }
    }
    closeTerminateDialog();
    if (navigator.vibrate) {
        navigator.vibrate(20);
    }
}

// Close dialog when clicking outside
document.getElementById('terminateDialog').addEventListener('click', function(e) {
    if (e.target === this) {
        closeTerminateDialog();
    }
});

// Logout Dialog functions
window.openLogoutDialog = function() {
    document.getElementById('logoutDialog').classList.add('active');
    if (navigator.vibrate) {
        navigator.vibrate(10);
    }
}

window.closeLogoutDialog = function() {
    document.getElementById('logoutDialog').classList.remove('active');
    if (navigator.vibrate) {
        navigator.vibrate(10);
    }
}

window.confirmLogout = function() {
    // Implement your logout logic here
    if (navigator.vibrate) {
        navigator.vibrate(20);
    }
    closeLogoutDialog();
    alert('Logged out successfully! You can implement your logout logic here.');
}

// Close logout dialog when clicking outside
document.getElementById('logoutDialog').addEventListener('click', function(e) {
    if (e.target === this) {
        closeLogoutDialog();
    }
});

// Sync username between header and settings
function updateUsername(name) {
    document.getElementById('username').textContent = name;
    document.getElementById('settings-username').textContent = name;
}

// Prevent pull-to-refresh on mobile
document.body.addEventListener('touchmove', (e) => {
    if (e.touches.length > 1) {
        e.preventDefault();
    }
}, { passive: false });