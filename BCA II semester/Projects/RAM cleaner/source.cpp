#include<iostream>
#include<stdlib.h>
#include<windows.h> // Using the following header file inorder to fetch terminal size for cosmetical purposes
#include<conio.h>
#include<vector>
class term_modifier{


    public:
    int rows;
    int columns;
     CONSOLE_SCREEN_BUFFER_INFO term; // CONSOLE_SCREEN_BUFFER_INFO is a structure variable that contains data members containing terminal data
    // Head point of the menu of the software
    HANDLE terminal_access = GetStdHandle(STD_OUTPUT_HANDLE); // Handle is like a permission ticket to a program to access window specific programs and modify its behavior besides windows itself modifying
    term_modifier(){
    // Fetching logic for the terminal size of the program
    if(GetConsoleScreenBufferInfo(terminal_access,&term)){
        columns = term.srWindow.Right - term.srWindow.Left + 1;
        rows = term.srWindow.Bottom - term.srWindow.Top + 1;
    }else{
        std::cout<<"class<termsize>:: Failed to access the program data"<<std::endl;
    }
}

    
    void clearScreen(){
        DWORD cells;
        COORD terminal_coordinates = {0, 0};
        cells = term.dwSize.X * term.dwSize.Y;
        DWORD count;
        FillConsoleOutputCharacter(terminal_access,' ',cells,terminal_coordinates,&count);
        FillConsoleOutputAttribute(terminal_access, term.wAttributes, cells, terminal_coordinates, &count);
        SetConsoleCursorPosition(terminal_access, terminal_coordinates);
     }

    

};

void centrePrintf(const char* text,int remove_columns){
    term_modifier t;
    for(int i = 1; i<=(t.columns/2) - (strlen(text)/2) - remove_columns; i++) std::cout<<" ";
    std::cout<<text;

}

void clearSyscache(){
    
}

int main(){
    term_modifier t;
    bool exit_flag = false;
    int current_selecion = 0;
    std::vector<std::string> options = {"Free-up RAM","Empty Standby RAM","Allocate Virtual RAM","Clear System Cache","Clear GPU shader cache","Exit Program"};
    while(!exit_flag){
    t.clearScreen();
    centrePrintf("Ram Cleaner and PC optimization utility software", 0);
    std::cout<<std::endl;
    centrePrintf("Version v1.0.0 Stable", 0);
    std::cout<<std::endl;
    for(int i = 1; i<=t.columns; i++) std::cout<<"-";
    for(int i = 0; i<options.size();i++){
        if(current_selecion == i){
                std::cout<<"->";
                centrePrintf(options[i].c_str(), 2);
                std::cout<<std::endl;
        }else{
                centrePrintf(options[i].c_str(), 0);
                std::cout<<std::endl;
        }
    }

    for(int i = 1; i<t.rows - 100;i++) std::cout<<std::endl;
    for(int i = 1; i<=t.columns; i++) std::cout<<"-";
    std::cout<<std::endl;
    std::cout<<"Use Arrow keys to navigate. UP, DOWN."<<std::endl<<"Select ENTER to choose."<<std::endl;
    char key = getch();
    if(key == 80 && current_selecion < options.size()-1){
        current_selecion++;
    }else if(key == 72 && current_selecion > 0){
        current_selecion--;
    }else if(key == 13){
        if(current_selecion == 5){
            exit_flag = 1;
            return 0;
        }else if(current_selecion == 3){
            clearSyscache();
        }

    }
    }
}