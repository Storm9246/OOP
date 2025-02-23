#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Robot {
    string robotName;
    int hits;

public:
    Robot(string n = "Unknown") : robotName(n), hits(0) {}

    void hitBall(int &ballX, int &ballY, const string &direction) {
        if (direction == "up") ballY++;
        else if (direction == "down") ballY--;
        else if (direction == "right") ballX++;
        else if (direction == "left") ballX--;
        else {
            cout << "Invalid direction! Try again." << endl;
            return;
        }
        hits++;
    }

    int getHits() const { return hits; }
    string getRobotName() const { return robotName; }
};

class Ball {
    int ball_x, ball_y;

public:
    Ball(int startX = 0, int startY = 0) : ball_x(startX), ball_y(startY) {}

    int getX() const { return ball_x; }
    int getY() const { return ball_y; }

    void move(int newX, int newY) {
        ball_x = newX;
        ball_y = newY;
    }

    pair<int, int> getPosition() const { return {ball_x, ball_y}; }
};

class Goal {
    int goal_x, goal_y;

public:
    Goal(int x = 3, int y = 3) : goal_x(x), goal_y(y) {}

    bool isGoalReached(int ballX, int ballY) const {
        return (goal_x == ballX && goal_y == ballY);
    }
};

class Team {
    string teamName;

public:
    Robot *robot;
    Team(string n = "Unnamed", Robot *r = nullptr) : teamName(n), robot(r) {}

    string getTeamName() const { return teamName; }
};

class Game {
    Team teamOne, teamTwo;
    Ball ball;
    Goal goal;

public:
    Game(Team t1, Team t2, int goalX = 3, int goalY = 3) : teamOne(t1), teamTwo(t2), goal(goalX, goalY) {}

    void startGame() {
        cout << "Let the game begin!" << endl;
        play(&teamOne);
        ball = Ball(); 
        play(&teamTwo);
        declareWinner();
    }

    void play(Team *team) {
        cout << "\nTeam \"" << team->getTeamName() << "\" is now playing." << endl;
        while (!goal.isGoalReached(ball.getX(), ball.getY())) {
            string dir;
            int ballX = ball.getX(), ballY = ball.getY();

            cout << "Ball position: (" << ballX << ", " << ballY << ")" << endl;
            cout << "Enter direction (up, down, left, right): ";
            cin >> dir;
            transform(dir.begin(), dir.end(), dir.begin(), ::tolower);

            team->robot->hitBall(ballX, ballY, dir);
            ball.move(ballX, ballY);
        }
        cout << "Ball reached the goal!" << endl;
        cout << "Team \"" << team->getTeamName() << "\" took " << team->robot->getHits() << " hits to score a goal!" << endl;
    }

    void declareWinner() {
        cout << "\n---- Game Over ----" << endl;
        if (teamOne.robot->getHits() < teamTwo.robot->getHits())
            cout << "Winner: Team \"" << teamOne.getTeamName() << "\" with Robot \"" << teamOne.robot->getRobotName() << "\" in " << teamOne.robot->getHits() << " hits!" << endl;
        else if (teamOne.robot->getHits() > teamTwo.robot->getHits())
            cout << "Winner: Team \"" << teamTwo.getTeamName() << "\" with Robot \"" << teamTwo.robot->getRobotName() << "\" in " << teamTwo.robot->getHits() << " hits!" << endl;
        else
            cout << "It's a tie!" << endl;
    }
};

int main() {
    int choice;
    do {
        cout << "\nFootball Game Simulation" << endl;
        cout << "1. Start Game" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string robotName1, robotName2, teamName1, teamName2;
            cout << "Enter Robot 1 name: "; cin >> robotName1;
            cout << "Enter Team 1 name: "; cin >> teamName1;

            cout << "Enter Robot 2 name: "; cin >> robotName2;
            cout << "Enter Team 2 name: "; cin >> teamName2;

            Robot robot1(robotName1), robot2(robotName2);
            Team team1(teamName1, &robot1), team2(teamName2, &robot2);

            Game game(team1, team2);
            game.startGame();
        }
        else if (choice != 2) {
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 2);
    
    cout << "Exiting..." << endl;
    return 0;
}
