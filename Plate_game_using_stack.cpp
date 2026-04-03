#include<iostream>
using namespace std;

//class for stack of plates.
class Plate_Stack{
    private:
        int top;
        int stack[10];
    public:
        int size;
        Plate_Stack(){
            top=-1;
            size = 10;
        }
//  to get the current number of plates in the stack after the game is over and to display the final stack of plates
    int get_current_plates(){
            return top + 1;
    }
// to add a plate to the stack, ensuring that the new plate is not heavier than the top plate
    void add_Plate(int weight){
                    if (top == size - 1) {
                        cout << "Stack overflow! Cannot add more plates." << endl;
                        return;
                    }
                    stack[++top] = weight; 
                }
// to remove the top plate from the stack, ensuring that the stack is not empty before attempting to remove a plate
    void remove_Plate(){
                    if (is_Stack_Empty()) {
                        cout << "Stack underflow! No plates to remove." << endl;
                        return;
                    }
                    top--; 
                }
// to view the weight of the top plate without modifying the stack, ensuring that the stack is not empty before attempting to view the top plate
    int view_Top_plate(){
            if(is_Stack_Empty()){
                cout << "Stack is empty! No plates to view." << endl;
                return -1 ; 
            }
            return stack[top];
        }
    bool is_Stack_Empty(){
            return top == -1;
        }
    void display_Stack(){
            if(is_Stack_Empty()){
                cout << "Stack is empty! No plates to display." << endl;
                return;
            }
            cout << "Current stack of plates (top to bottom): ";
            for(int i = top; i >= 0; i--){
                cout << stack[i] << " ";
            }
            cout << endl;
        }
};
int main(){
    Plate_Stack plateStack;
    int scores = 0;
    int attempts = 0;
    bool isGameOver = false;
    int weight;
// to display the game rules and instructions to the player at the start of the game
    cout << "                 ..............Welcome to.........." << endl;
    cout << "                 === PLATE STACK BALANCING GAME ===" << endl;
    cout << "                            === Rules ===" << endl;
    cout << "-> Stack 5 plates to WIN" << endl;
    cout << "-> Max 10 attempts allowed" << endl;
    cout << "-> New plate must be <= Top plate weight" << endl;
    cout << "-> Heavier plate on lighter Game Over" << endl;
    cout << "-> Score: +2 for Push, -1 for Pop" << endl << endl;
// to implement the main game loop, allowing the player to choose actions and updating the game state accordingly until the game is over
// so the loop will continue until the player either wins by stacking 5 plates
// loses by adding a heavier plate on top or exhausts all 10 attempt
// menu Actions.
while (!isGameOver && attempts < 10) {    
        cout<<"Menu:\n1) Add Plate\n2) Remove Plate\n3) View Top Plate\n4) Display Stack\n5) Exit"<<endl;
        int choice;
        // read menu choice and validate input type
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter 1-5." << endl;
            continue;
        }
        // Validate menu choice range
        if (choice < 1 || choice > 5) {
            cout << "Invalid choice! Please enter 1-5." << endl;
            continue;
        }
        switch(choice){
            // adding the plates.
            case 1:
            //counting attempts..
                attempts++;
                cout << "Enter the weight of the plate to add: ";
                cin >> weight;
            //weight must be positive integer
                if(weight <= 0){
                    cout << "Invalid weight! Please enter a positive integer (> 0)." << endl;
                    break;
                }
            // check if stack is empty. and update the score +2.
            if (plateStack.is_Stack_Empty()) {
            plateStack.add_Plate(weight);
            scores += 2;
            cout << "Plate added successfully!" << endl;
        } 
        // check if the new plate is heavier than the top plate. if it is heavier, the game is over and the player loses
            else if(weight > plateStack.view_Top_plate()){
            cout << "You lose! The new plate is heavier than the top plate." << endl;
            isGameOver = true;
        } 
        // if the new plate is lighter than or equal to the top plate it is added to the stack and the score is updated +2.
            else if(weight <= plateStack.view_Top_plate()){
            cout << "Plate added successfully!" << endl;
            plateStack.add_Plate(weight);
            scores += 2;
        }
            break;

        // removing the plates.
            case 2:
        //counting attempts
                attempts++;
            // check if the stack is empty befre removing the top plate.
            if (plateStack.is_Stack_Empty()) {
            cout << "Cannot remove! Stack is empty." << endl;
        }   else {
            scores -= 1;
            plateStack.remove_Plate();
            cout << "Plate removed! (-1 point)" << endl;
            // if the stack is not empty after removing the top plate, display the new top plate. 
            //if the stack becomes empty inform the player that the stack is now empty.
            if (!plateStack.is_Stack_Empty()) {
            cout << "New top plate: " << plateStack.view_Top_plate() << endl;
        }   else {
            cout << "Stack is now empty!" << endl;
        }
    }
            break;
        // viewing the top plate.
            case 3:
                attempts++; // View action counts as an attempt
                cout << "Top plate: " << plateStack.view_Top_plate() << endl;
                break;
        // displaying the stack of plates.
            case 4:
                plateStack.display_Stack();
                break;
        // exiting the game.
            case 5:
                isGameOver = true;
                cout << "Exiting the game. Thanks for playing!" << endl;
                break;
        default:
                cout << "Invalid choice! Please try again." << endl;
        }
                if (plateStack.get_current_plates() == 5) {
                cout << "Hey Dude! you Added 5 plates and won the game!" << endl;
                isGameOver = true;
        }
    }
    //displaying the final score,stack of plates and attempts..
    cout << "Final score: " << scores << endl;
    cout << "Total attempts: " << attempts << endl;
    cout<<"Final Stack:" << endl;
    plateStack.display_Stack();
    cout << "Thanks for playing!" << endl;
    
    return 0;
}