#include <iostream>
using namespace std;


class plot{
    private:
    int grid[10][10] = {0}; // intialize every single box in the grid to 0 so we can compare it against -1 later on
    int gridb[10][10] = {-10};

    public:
    void place_bombs(){

        // placed 10 bombs in the grid, where -1 represents a bomb

        int x_val, y_val;

        for(int i = 0; i < 10; i++){
            x_val = rand()%10;
            y_val = rand()%10;
            grid[x_val][y_val] = -1;
        }


        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                if(grid[i][j] == 0 ){ // if it is not a bomb
                    //check the box below
                    if(j+1 < 10 ){
                        if(grid[i][j+1] == -1) grid[i][j]++;
                    }
                    
                    //check the box above
                     if(j-1 >= 0 ){
                        if(grid[i][j-1] == -1) grid[i][j]++;
                    }

                    //check the box to the left
                     if(i-1 >= 0 ){
                        if(grid[i-1][j] == -1) grid[i][j]++;
                    }

                    //checl the box to the right
                     if(i+1 < 10 ){
                        if(grid[i+1][j] == -1) grid[i][j]++;
                    }

                    //check the top left
                    if(j-1>= 0 && i-1 >= 0){
                        if(grid[i-1][j-1] == -1) grid[i][j]++;
                    }

                    //check the top right
                    if(j+1< 10 && i-1 >= 0){
                        if(grid[i-1][j+1] == -1) grid[i][j]++;
                    }

                    //check bottom left
                    if(i+1<10 && j-1>= 0){
                        if(grid[i+1][j-1] == -1) grid[i][j]++;
                    }

                    //check the bottom right 
                    if(i+1<10 && j+1< 10){
                        if(grid[i+1][j-1] == -1) grid[i][j]++;
                    }

                }   
            }
        }

    

    }

    void display_grid(){
        for(int i = 0 ; i < 10 ; i++){
            for(int j = 0; j < 10; j++){
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }

    void display_gridb(){
        for(int i = 0 ; i < 10 ; i++){
            for(int j = 0; j < 10; j++){
                if(gridb[i][j] != -10){
                    cout << gridb[i][j] << " ";
                } else{
                    cout << "  ";
                }
                
            }
            cout << endl;
        }
    }

    bool open_grid(int x_value, int y_value){
        // in case they click on a bomb

        if(gridb[x_value][y_value] == -10) return true;

        if(grid[x_value][y_value] == -1){
            cout << "Game Over!" << endl;
            display_grid();
            return false;
        }
        else if(grid[x_value][y_value] > 0){
            gridb[x_value][y_value] = grid[x_value][y_value];
            return true;
        }
        else{
            gridb[x_value][y_value] = 0;
            if(y_value+1 < 10 ){
                open_grid(x_value, y_value+1);
                }
                    
            //check the box above
            if(y_value-1 >= 0 ){
                open_grid(x_value, y_value -1);
                }

            //check the box to the left
            if(x_value-1 >= 0 ){
                open_grid( x_value-1,y_value);
                }

            //checl the box to the right
            if(x_value+1 < 10 ){
                open_grid(x_value+1, y_value);
            }

            //check the top left
            if(y_value-1>= 0 && x_value-1 >= 0){
                open_grid(x_value-1,y_value-1);
            }

            //check the top right
            if(y_value+1< 10 && x_value-1 >= 0){
                open_grid( x_value-1,y_value+1);
            }

            //check bottom left
            if(x_value+1<10 && y_value-1>= 0){
                open_grid(x_value+1, y_value -1);
            }

            //check the bottom right 
            if(x_value+1<10 && y_value+1< 10){
                open_grid( x_value+1,y_value+1);
            }

            return true;
        }
    }

};

int main(void){
    plot comp_grid;
    comp_grid.place_bombs();

    while(true){
        int x,y;
        cout << "Enter the co-ordinaes of block you'd like to open, separated by a space. Please ensure the values you enter for each place are between 0 and 9 " << endl;;
        cin >> x >> y;
        if(x < 0 || x > 9 || y < 0 || y > 9){
            cout << "Invalid co-ordinate, please try again" << endl;
        } 
        else{
            bool response = comp_grid.open_grid(x, y);
            if(response){
                comp_grid.display_gridb();
            }
            else{
                break;
            }
            
        }


    }

}