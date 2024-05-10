

    #include <iostream>
    #include<windows.h>
    using namespace std ;

    int currentPlayer=0;
    int percentage=60;
    int move=0; 

    char board[8][8] = {
            {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
        };


    void displayrules()
    {   
        
        int x;


    while(x!=6){
        cout << "**************************" << endl;
        cout << "      Welcome to Chess    " << endl;
        cout << "**************************" << endl;
        cout<< " Enter which piece tou want to know rules\n";
        cout << "1. King" << endl;
        cout << "2. Queen" << endl;
        cout << "3. Rook" << endl;
        cout << "4. Bishop" << endl;
        cout << "5. Knight" << endl;
        cout << "6. Exit" << endl;
        cout << "**************************" << endl;
        cin>>x;
        switch (x)
        {
            case 1:
                cout << "King: The king can move one square in any direction (horizontally, vertically, or diagonally)." << endl;
                break;
            case 2:
                cout << "Queen: The queen can move any number of squares in any direction (horizontally, vertically, or diagonally)." << endl;
                break;
            case 3:
                cout << "Rook: The rook can move any number of squares horizontally or vertically." << endl;
                break;
            case 4:
                cout << "Bishop: The bishop can move any number of squares diagonally." << endl;
                break;
            case 5:
                cout << "Knight: The knight moves to any of the squares immediately adjacent to it, and then makes a second move 90 degrees from the first move." << endl;
                break;
            case 6:
            break;
            default:
                cout << "Invalid option. Please try again." << endl;
            
            break;
        }
    }
    }



    void showProgressBar(int percentage) {
        cout << "Loading: ";
        int width = 40;
        int complete = width * percentage / 100;
        int remaining = width - complete;
        cout << "[";
        for (int i = 0; i < complete; i++) {
            cout << "%";
        }
        for (int i = 0; i < remaining; i++) {
            cout << "-";
        }
        cout << "] " << percentage << "%\r";
        cout.flush();
    }


    void setConsoleColor(int textColor, int bgColor) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, (textColor + (bgColor * 16)));
    }

    // Function to print the chessboard
    void printBoard(char board[8][8]) {
        cout<<"  0   1   2   3   4   5   6   7\n";
        for(int i=0; i<8; i++) {
            cout << "+---+---+---+---+---+---+---+---+" << endl;
            for(int j=0; j<8; j++) {
                cout << "| " << board[i][j] << " ";
            }
            cout << "|" << " "<<i<< endl;
        }
        cout << "+---+---+---+---+---+---+---+---+" << endl;
        
    }


    bool isValidKingMove( int startX, int startY, int endX, int endY) {
        // Check if the start and end positions are within the bounds of the board
        if (startX < 0 || startX >= 8 || startY < 0 || startY >= 8 )
        return false;

        if( endX < 0 || endX >= 8 || endY < 0 || endY >= 8) {
            return false;
        }

        // Check if the start position contains a piece belonging to the same player
        if ((board[startX][startY] >= 'A' && board[startX][startY] <= 'Z') && (board[endX][endY] >= 'A' && board[endX][endY] <= 'Z')) {
            return false;
        }
        
        if ((board[startX][startY] >= 'a' && board[startX][startY] <= 'z') && (board[endX][endY] >= 'a' && board[endX][endY] <= 'z')) {
            return false;
        }
    
    /*
    Suppose we have the following values:

    startX = 3
    startY = 4
    endX = 4
    endY = 5
    To determine if this move is within the king's range, the code calculates the absolute differences in positions:

    diffX = abs(endX - startX) = abs(4 - 3) = 1
    diffY = abs(endY - startY) = abs(5 - 4) = 1
    Now, the code checks if both diffX and diffY are less than or equal to 1
    */
        // Calculate the absolute differences in positions
        double diffY = abs(endY - startY);
        double diffX = abs(endX - startX);

        // Check if the move is within the king's range
        if (diffX <= 1 && diffY <= 1) {
            // Valid move for the king
            return true;
        }

        // Invalid move for the king
        return false;
    }
    /*Suppose we have a bishop on a chessboard, and it wants to move from position (2, 3) to position (5, 6).

    In this case, the start position is (2, 3), where startX = 2 and startY = 3. The end position is (5, 6), where endX = 5 and endY = 6.

    To calculate the absolute difference in the X coordinates, we subtract the start X coordinate from the end X coordinate and take the absolute value:

    diffX = abs(endX - startX) = abs(5 - 2) = abs(3) = 3

    The absolute difference in the X coordinates is 3.

    Similarly, we calculate the absolute difference in the Y coordinates by subtracting the start Y coordinate from the end Y coordinate and taking the absolute value:

    diffY = abs(endY - startY) = abs(6 - 3) = abs(3) = 3

    The absolute difference in the Y coordinates is also 3.

    In this example, both the absolute differences in the X and Y coordinates are equal, indicating a diagonal move for the bishop.
    */

    bool isValidBishopMove( int startX, int startY, int endX, int endY) {
    // Check if the start and end positions are within the bounds of the board
        if (startX < 0 || startX >= 8 || startY < 0 || startY >= 8 )
        return false;

        if( endX < 0 || endX >= 8 || endY < 0 || endY >= 8) {
            return false;
        }   
        // Check if the start position contains a piece belonging to the same player
        if ((board[startX][startY] >= 'a' && board[startX][startY] <= 'z') && (board[endX][endY] >= 'a' && board[endX][endY] <= 'z')) {
            return false;
        }
        if ((board[startX][startY] >= 'A' && board[startX][startY] <= 'Z') && (board[endX][endY] >= 'A' && board[endX][endY] <= 'Z')) {
            return false;
        }

        // Calculate the absolute differences in positions
        int diffX = abs(endX - startX);
        int diffY = abs(endY - startY);

        // Check if the move is diagonal (both X and Y differences are the same)
        if (diffX == diffY) {
            // Check if there are any obstacles in the path of the bishop
            int stepX;
            int stepY;

            if (endX > startX) {
            stepX = 1;
            } else {
            stepX = -1;
            }

            if (endY > startY) {
        stepY = 1;
            } else {
        stepY = -1;
            }

            int x = startX + stepX;
            int y = startY + stepY;

            while (x != endX && y != endY) {
                if (board[x][y] != ' ') {
                    // There is an obstacle in the path of the bishop
                    return false;
                }
            // If endX is greater than startX, stepX is set to 1, indicating the bishop is moving to the right. 
                x += stepX; //Otherwise, stepX is set to -1, indicating the bishop is moving to the left. Similarly, stepY is set based on the comparison of endY and startY.
                y += stepY;
            }

            // Valid move for the bishop
            return true;
        }

        // Invalid move for the bishop
        return false;
    }

    
    bool isValidRookMove( int startX, int startY, int endX, int endY) {
        // Check if the start and end positions are within the bounds of the board
        if (startX < 0 || startX >= 8 || startY < 0 || startY >= 8 ||
            endX < 0 || endX >= 8 || endY < 0 || endY >= 8) {
            return false;
        }

        // Check if the start position contains a piece belonging to the same player
        if ((board[startX][startY] >= 'a' && board[startX][startY] <= 'z') && (board[endX][endY] >= 'a' && board[endX][endY] <= 'z')) {
            return false;
        }
        if ((board[startX][startY] >= 'A' && board[startX][startY] <= 'Z') && (board[endX][endY] >= 'A' && board[endX][endY] <= 'Z')) {
            return false;
        }

        // Calculate the absolute differences in positions
        int diffX = abs(endX - startX);
        int diffY = abs(endY - startY);
        /*
        example, the rook starts at position (2, 3) and needs to reach position (5, 1).the code first determines the step size along the x-axis (stepX). 
        It compares the endX and startX values to decide the direction of movement.Since endX (5) is greater than startX (2), the condition endX > startX is true. 
        Therefore, stepX is assigned a value of 1, indicating movement towards the right. 
        Since endY (1) is less than startY (3), the condition endY < startY is true. Hence, stepY is assigned a value of -1, indicating movement upwards.
        Now, we have stepX = 1 and stepY = -1, which means the rook will move one step to the right and one step upward in each iteration until it reaches the destination.*/
        // Check if the move is along a straight line (either only X or only Y difference)
        if ((diffX > 0 && diffY == 0) || (diffX == 0 && diffY > 0)) {
            // Check if there are any obstacles in the path of the rook
            /**/
            int stepX;
            int stepY;

            if (endX > startX) {
            stepX = 1;
            } else if (endX < startX) {
            stepX = -1;
            } else {
            stepX = 0;
            }

            if (endY > startY) {
            stepY = 1;
            } else if (endY < startY) {
            stepY = -1;
            } else {
            stepY = 0;
            }
            /* For example, if the starting position is (2, 3) and the steps are (1, 0),
            then x would be assigned 2 + 1 = 3, and y would be assigned 3 + 0 = 3.
            The while loop checks whether the current position (x, y) is equal to the desired ending position (endX, endY). 
            If the rook hasn't reached the ending position, the loop continues.*/
    
                int x = startX + stepX;
                int y = startY + stepY;
        while (x != endX || y != endY) {
                    if (board[x][y] != ' ') {
                        // There is an obstacle in the path of the rook
                        return false;
                    }
                    x += stepX;
                    y += stepY;
                }

            // Valid move for the rook
            return true;
        }

        // Invalid move for the rook
        return false;
    }


    bool isValidQueenMove(int startX, int startY, int endX, int endY) {
        // Check if the start and end positions are within the bounds of the board
        if (startX < 0 || startX >= 8 || startY < 0 || startY >= 8 ||
            endX < 0 || endX >= 8 || endY < 0 || endY >= 8) {
            return false;
        }

        // Check if the start position contains a piece belonging to the same player
        if ((board[startX][startY] >= 'a' && board[startX][startY] <= 'z') && (board[endX][endY] >= 'a' && board[endX][endY] <= 'z') ) {
            return false;
        }
        if ((board[startX][startY] >= 'A' && board[startX][startY] <= 'Z') && (board[endX][endY] >= 'A' && board[endX][endY] <= 'Z')) {
        return false;
        }

        // Calculate the absolute differences in positions
        int diffX = abs(endX - startX);
        int diffY = abs(endY - startY);

        // Check if the move is along a straight line (either only X or only Y difference)
        if ((diffX > 0 && diffY == 0) || (diffX == 0 && diffY > 0)) {
            // Check if there are any obstacles in the path of the queen (rook movement)
            int stepX, stepY;
        if (endX > startX) {
        stepX = 1;
        } else if (endX < startX) {
        stepX = -1;
        } else {
        stepX = 0;
        }

        if (endY > startY) {
        stepY = 1;
        } else if (endY < startY) {
        stepY = -1;
        } else {
        stepY = 0;
        }

            int x = startX + stepX;
            int y = startY + stepY;

            while (x != endX || y != endY) {
                if (board[x][y] != ' ') {
                    // There is an obstacle in the path of the queen
                    if ((board[x][y] == 'k' || board[x][y] == 'K') && (diffX == 1 || diffY == 1)) {
                        return false;  // Obstacle is the king piece, valid move
                    }
                    return false;
                }
                x += stepX;
                y += stepY;
            }

            // Valid move for the queen
            return true;
        }
        // Check if the move is along a diagonal line
        else if (diffX == diffY) {
            // Check if there are any obstacles in the path of the queen (bishop movement)
            int stepX, stepY;
        if (endX > startX)  {
        stepX = 1;
        } else {
        stepX = -1;
        }
        if (endY > startY) {
        stepY = 1;
        } else {
        stepY = -1;
        }

            int x = startX + stepX;
            int y = startY + stepY;

            while (x != endX && y != endY) {
                if (board[x][y] != ' ') {
                    if ((board[x][y] == 'k' || board[x][y] == 'K') && (diffX == 1 || diffY == 1)) {
                        return false;  // Obstacle is the king piece, valid move
                    }
                
                    // There is an obstacle in the path of the queen
                    return false;
                }
                x += stepX;
                y += stepY;
            }

            // Valid move for the queen
            return true;
        }

        // Invalid move for the queen
        return false;
    }

    bool isValidKnightMove( int startX, int startY, int endX, int endY) {
        // Check if the start and end positions are within the bounds of the board
        if (startX < 0 || startX >= 8 || startY < 0 || startY >= 8 ||
            endX < 0 || endX >= 8 || endY < 0 || endY >= 8) {
            return false;
        }

        // Check if the start position contains a piece belonging to the same player
        if ((board[startX][startY] >= 'a' && board[startX][startY] <= 'z') && (board[endX][endY] >= 'a' && board[endX][endY] <= 'z') && (board[endX][endY]=='K')) {
            return false;
        }
        if ((board[startX][startY] >= 'A' && board[startX][startY] <= 'Z') && (board[endX][endY] >= 'A' && board[endX][endY] <= 'Z') && (board[endX][endY]=='K')) {
            return false;
        }

        // Calculate the absolute differences in positions
        int diffX = abs(endX - startX);
        int diffY = abs(endY - startY);

        // Check if the move is in the L-shape of a knight
        if ((diffX == 2 && diffY == 1) || (diffX == 1 && diffY == 2)) {
            // Valid move for the knight
            return true;
            
        }

        // Invalid move for the knight
        return false;
    }

    int getPlayer(char piece) {
        // Returns the player based on the piece symbol
        if (piece >= 'a' && piece <= 'z') {
            // Lowercase letters represent player 1 (black)
            return 1;
        } else if (piece >= 'A' && piece <= 'Z') {
            // Uppercase letters represent player 2 (white)
            return 2;
        }
        // Invalid or empty square
        return 0;
    }

    bool capturesOwnPiece(char board[8][8], int startX, int startY, int endX, int endY) {
        // Check if the move captures the player's own piece
        char startPiece = board[startX][startY];
        char endPiece = board[endX][endY];

        if (startPiece == ' ' || endPiece == ' ') {
            // No piece to capture
            return false;
        }

        int startPlayer = getPlayer(startPiece);
        int endPlayer = getPlayer(endPiece);

        // Check if the end position contains a piece of the same player
        if (startPlayer == endPlayer) {
            return true;
        }

        return false;
    }

    bool isValidMove(int startX, int startY, int endX, int endY) {
        // Check if the start position is on the board
        if (startX < 0 || startX >= 8|| startY < 0 || startY >= 8) {
            return false;
        }
        // Check if the end position is on the board
        if (endX < 0 || endX >= 8 || endY < 0 || endY >= 8) {
            return false;
        }
        // Check if the start position is not empty
        if (board[startX][startY] == ' ') {
            return false;
        }
        // Check if the end position is occupied by the player's own piece
        if (board[endX][endY] !=' ' && board[startX][startY] == board[endX][endY]) {
            return false;
        }
        // Check if the move is valid for the piece being moved
        switch (board[startX][startY]) {

            case 'K':
                return isValidKingMove(startX, startY, endX, endY);
            break;
            case 'k':
                return isValidKingMove(startX, startY, endX, endY);
            break;
            case 'N':
            return isValidKnightMove(startX, startY, endX, endY);
            break;
            case 'n':
                return isValidKnightMove(startX, startY, endX, endY);
            case 'Q':
                return isValidQueenMove(startX, startY, endX, endY);

            break;
            case 'q':
                return isValidQueenMove(startX, startY, endX, endY);
            case 'R':
                return isValidRookMove(startX, startY, endX, endY);

            break;
            case 'r':
                return isValidRookMove(startX, startY, endX, endY);
            break;
            case 'B':
                return isValidBishopMove(startX, startY, endX, endY);
            
            break;
            case 'b':
            
                return isValidBishopMove(startX, startY, endX, endY);
            break;
            default:
                return false;
                break;
        }
    }




    void showValidMoves(char board[8][8], int startX, int startY) {
        char piece = board[startX][startY];

        // Check if the start position contains a piece belonging to the current player
        if ((piece >= 'a' && piece <= 'z')||( piece >= 'A' && piece <='Z')) {
            cout << "Valid moves for the selected piece (" << piece << ") at position (" << startX << ", " << startY << "):" << endl;

            // Iterate through all possible end positions
            for (int endX = 0; endX < 8; endX++) {
                for (int endY = 0; endY < 8; endY++) {
                    // Check if the move is valid based on the piece type
                    bool isValidMove = false;

                    switch (tolower(piece)) {
                        
                        case 'r':
                            isValidMove = isValidRookMove( startX, startY, endX, endY);
                            break;
                        case 'R':
                            isValidMove = isValidRookMove( startX, startY, endX, endY);

                        break;
                        case 'N':
                            isValidMove = isValidKnightMove( startX, startY, endX, endY);
                        
                        break;
                        case 'n':
                            isValidMove = isValidKnightMove( startX, startY, endX, endY);
                            break;
                        case 'b':
                            isValidMove = isValidBishopMove( startX, startY, endX, endY);
                            break;
                        case 'B':
                            isValidMove = isValidBishopMove( startX, startY, endX, endY);
                        
                        break;
                        case 'q':
                            isValidMove = isValidQueenMove( startX, startY, endX, endY);
                            break;
                        case 'Q':
                            isValidMove = isValidQueenMove( startX, startY, endX, endY);
                            break;
                        case 'k':
                            isValidMove = isValidKingMove(startX, startY, endX, endY);
                            break;
                        case 'K':
                            isValidMove = isValidKingMove(startX, startY, endX, endY);
                            break;                      
                    }

                    // If the move is valid, and it does not capture the player's own piece, display the move
                    if (isValidMove && !capturesOwnPiece(board, startX, startY, endX, endY)) {
                        
                    cout << "(" << startX << ", " << startY << ") -> (" << endX << ", " << endY << ")" << endl;

                    }
                }
            }
        }
        else {
            
            cout << "No valid moves. Please select a valid piece." << endl;
            

        }
    }

    void showValidMovesForPlayer(char board[8][8], int currentPlayer) {
        cout << "Valid moves for Player " << currentPlayer << ":" << endl;

        // Iterate through all positions on the board
        for (int startX = 0; startX < 8; startX++) {
            for (int startY = 0; startY < 8; startY++) {
                char piece = board[startX][startY];

                // Check if the piece belongs to the current player
                if ((currentPlayer == 1 && (piece >= 'A' && piece <= 'Z')) ||
                    (currentPlayer == 2 && (piece >= 'a' && piece <= 'z'))) {

                    // Check if the piece has any valid moves
                    showValidMoves(board, startX, startY);
                }
            }
        }
    }

    bool isInCheck(const char board[8][8], int currentPlayer) {
        // Find the position of the current player's king
        int kingX = -1;
        int kingY = -1;
        char kingPiece = (currentPlayer == 1) ? 'K' : 'k';

        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                if (board[x][y] == kingPiece) {
                    kingX = x;
                    kingY = y;
                    break;
                }
            }
            if (kingX != -1 && kingY != -1) {
                break;
            }
        }

        // Check if any opponent's piece can capture the king
        char opponentKingPiece = (currentPlayer == 1) ? 'k' : 'K';

        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                char piece = board[x][y];

                // Check if the piece belongs to the opponent
                if ((currentPlayer == 1 && islower(piece)) ||
                    (currentPlayer == 2 && isupper(piece))) {

                    // Check if the opponent's piece can capture the king
                    if (isValidMove( x, y, kingX, kingY)) {
                        // The king is in check
                        return true;
                    }
                }
            }
        }

        // The king is not in check
        return false;
    }

    bool gameOver(char board[8][8], int currentPlayer) {


    // If the king is in check, the game is over
    if (isInCheck(board,currentPlayer)) {
        cout << "Game Over! Player " << currentPlayer << " is in checkmate." << endl;
        return true;
    }

    return false;

    }


    // Function to play the game
    int playGame() {
    

        int startX, startY, endX, endY;
    

        while (true) {
            setConsoleColor(14,0);
            showProgressBar(100);
            cout<<endl;
            cout<<endl;
            
            char choice;
            // Player 1's turn (White)
            
            
    while (true) {
            currentPlayer =1;

        printBoard(board);
        
        
    cout << "Player "<< currentPlayer<<" (white)\n ";
            while (true) {
        cout << "Enter which piece you want to move\n";
        cin >> choice;
        
        // Input validation for choice
        if (choice != 'R' && choice != 'K' && choice != 'Q' && choice != 'N' && choice != 'B') {
            cout << "Enter correct name of piece\n";
            continue;
        }
        
        if (choice == 'R') {
            bool pieceFound = false;
            for(int i = 0; i < 8; i++) {
                for(int j = 0; j < 8; j++) {
                    if(board[i][j] == choice) {
                        pieceFound = true;
                        break;
                    }
                }
                if (pieceFound) {
                    break;
                }
            }
            if (!pieceFound) {
                cout << "The piece has been killed by the opponent\n";
                continue;
            }
            
            cout << "Enter start position of piece " << choice << " as (x,y) coordinates\n";
            cin >> startX >> startY;
            
            while (startX < 0 || startX >= 8 || startY < 0 || startY >= 8 || board[startX][startY] != choice) {
                cout << "Invalid position or your desired piece isn't in that location\n";
                cout << "Please enter again\n";
                cout << "Enter start position of piece " << choice << " as (x,y) coordinates\n";
                cin >> startX >> startY;
            }
            
            break;
        }
        else if (choice == 'K' || choice == 'Q') {
            bool pieceFound = false;
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (board[i][j] == choice) {
                        startX = i;
                        startY = j;
                        pieceFound = true;
                        break;
                    }
                }
                if (pieceFound) {
                    break;
                }
            }
            if (!pieceFound) {
                cout << "The piece has been killed by the opponent\n";
                continue;
            }
            
            break;
        }
        else if (choice == 'N' || choice == 'B') {
            cout << "Enter start position of piece " << choice << " as (x,y) coordinates\n";
            cin >> startX >> startY;
            
            while (startX < 0 || startX >= 8 || startY < 0 || startY >= 8 || board[startX][startY] != choice) {
                cout << "Invalid position or your desired piece isn't in that location\n";
                cout << "Please enter again\n";
                cout << "Enter start position of piece " << choice << " as (x,y) coordinates\n";
                cin >> startX >> startY;
            }
            
            break;
        }
    }


        
            
            
            showValidMoves(board, startX, startY);
            cin >> endX >> endY;
                if (isValidMove(startX, startY, endX, endY)) {
                board[endX][endY] = board[startX][startY];
                board[startX][startY] = ' ';
                    break;
                }
                else {
                cout << "Invalid move! Try again." << endl;
                continue;

                }
            

            }

            if(gameOver(board,currentPlayer))
            break;
        
            // Player 2's turn (Black)
        
            currentPlayer=2;
        
            while (true) {
                printBoard(board);
        
            cout << "Player "<< currentPlayer<<" (Black)\n ";

            while (true) {
        cout << "Enter which piece you want to move\n";
        cin >> choice;
        
        // Input validation for choice
        if (choice != 'r' && choice != 'k' && choice != 'q' && choice != 'n' && choice != 'b') {
            cout << "Enter correct name of piece\n";
            continue;
        }
        
        if (choice == 'r') {
            bool pieceFound = false;
            for(int i = 0; i < 8; i++) {
                for(int j = 0; j < 8; j++) {
                    if(board[i][j] == choice) {
                        pieceFound = true;
                        break;
                    }
                }
                if (pieceFound) {
                    break;
                }
            }
            if (!pieceFound) {
                cout << "The piece has been killed by the opponent\n";
                continue;
            }
            
            cout << "Enter start position of piece " << choice << " as (x,y) coordinates\n";
            cin >> startX >> startY;
            
            while (startX < 0 || startX >= 8 || startY < 0 || startY >= 8 || board[startX][startY] != choice) {
                cout << "Invalid position or your desired piece isn't in that location\n";
                cout << "Please enter again\n";
                cout << "Enter start position of piece " << choice << " as (x,y) coordinates\n";
                cin >> startX >> startY;
            }
            
            break;
        }
        else if (choice == 'k' || choice == 'q') {
            bool pieceFound = false;
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (board[i][j] == choice) {
                        startX = i;
                        startY = j;
                        pieceFound = true;
                        break;
                    }
                }
                if (pieceFound) {
                    break;
                }
            }
            if (!pieceFound) {
                cout << "The piece has been killed by the opponent\n";
                continue;
            }
            
            break;
        }
        else if (choice == 'n' || choice == 'b') {
            cout << "Enter start position of piece " << choice << " as (x,y) coordinates\n";
            cin >> startX >> startY;
            
            while (startX < 0 || startX >= 8 || startY < 0 || startY >= 8 || board[startX][startY] != choice) {
                cout << "Invalid position or your desired piece isn't in that location\n";
                cout << "Please enter again\n";
                cout << "Enter start position of piece " << choice << " as (x,y) coordinates\n";
                cin >> startX >> startY;
            }
            
            break;
        }
        }
            showValidMoves(board, startX, startY);
            cin >> endX >> endY;
                if (isValidMove(startX, startY, endX, endY)) {
                board[endX][endY] = board[startX][startY];
                board[startX][startY] = ' ';
                    break;
                }
                else {
                cout << "Invalid move! Try again." << endl;
                continue;

                }
            

            }
        
            showProgressBar(100);
            cout<<endl;
            // Check for game over
            if(gameOver(board, currentPlayer))
            break;
        
        }
        
    }

    // Main function
    int main() {
        
        int choice;
            setConsoleColor(14,0);

        for (int i = 0; i <= 100; i++) {
            showProgressBar(i);
            }
        do{
        cout<<endl;
        cout << "**************************" << endl;
        cout << "      Welcome to Chess    " << endl;
        cout << "**************************" << endl;
        cout << " 1. Display Instructions\n";
        cout << " 2. Play Game\n";
        cout << " 3. Exit\n";
        
        cout << "Enter your choice: ";
        cin >> choice;

            if (choice == 1) 
            {   
            for (int i = 0; i <= 100; i++) {
            showProgressBar(i);
            }
                cout<<endl;
                displayrules();
                cout << "**************************" << endl;
            }
            else if(choice ==2){
            cout<<playGame();
            break;
            cout<<endl;
            }

            else if (choice == 3)
            {
                cout << "Exiting the game. Goodbye!" << endl;
            }
            else
            {
                cout << "Invalid option. Please try again." << endl;
            }
        } while (choice != 3);
        return 0;
    }
