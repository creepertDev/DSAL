// 23303
// To implement and demonstrate the working of a Priority Queue and a Double-Ended Queue (Deque) supporting standard operations such as insertion, deletion, and display.
// news website management system

#include <iostream>
#include <cstring>
using namespace std;

// defining maximum size for articles array
#define maxArticlesSize 15

#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <iomanip>

// structure to store news article information
struct newsArticle
{
    int priorityNum;      // priority number (1=breaking, 2=international, etc.)
    string headline;      // article headline
    string article;       // article body/content
};

// defining newsArticle as a type
typedef struct newsArticle newsArticle;

// class to manage news website operations
class newsWebsite
{
private:
    // array to store all news articles
    newsArticle nw[maxArticlesSize];
    
    // tracks the position of last article in array
    int lastArticle;

public:
    // function to create a new article by taking user input
    newsArticle newArticle();
    
    // function to convert string priority type to integer
    int priorityDecider(string newsType);
    
    // function to convert integer priority to string type
    string priorityDecider(int newsType);
    
    // function to load articles from CSV file
    void loadCSV(string csvFile);
    
    // function to save articles to CSV file
    void saveToCSV(string csvFile);
    
    // function to insert article at correct priority position
    void insertArticle(newsArticle newArticle);
    
    // function to push articles from a given position (make space)
    void pushArticleFromPos(int x);
    
    // function to find position of first article with given priority
    int positionFinder(int x);
    
    // function to delete article at given position
    void deleteArticle(int x);
    
    // function to display all articles on screen
    void displayAllArticles();
    
    // function to delete all articles with priority 1 (breaking news)
    void deleteBasedOnPriority();

    // constructor to load CSV file on object creation
    newsWebsite(string csvFile)
    {
        loadCSV(csvFile);
    }
};

// deletes all articles with priority 1 (breaking news)
void newsWebsite::deleteBasedOnPriority()
{
    int x = 0;
    
    // keep deleting while articles at position 0 have priority 1
    while (nw[x].priorityNum == 1)
    {
        deleteArticle(x);
    }
    return;
}

// displays all articles in the news website
void newsWebsite::displayAllArticles()
{
    // clear the screen
    system("clear");
    
    cout << "                                           XYZ NEWS" << endl;
    int x = 0;
    
    // loop through all articles and display them
    while (x != lastArticle)
    {
        cout << x + 1 << " . " << priorityDecider(nw[x].priorityNum) << " : " << nw[x].headline << endl
             << nw[x].article << "\n"
             << endl;
        x++;
    }
    return;
}

// deletes article at position x by shifting all subsequent articles
void newsWebsite::deleteArticle(int x)
{
    int y = x;
    
    // shift all articles after position x one position back
    while (y != lastArticle)
    {
        nw[y] = nw[y + 1];
        y++;
    }

    // decrement the last article counter
    lastArticle--;
    return;
}

// creates a new article by taking input from user
newsArticle newsWebsite::newArticle()
{
    newsArticle newArticleObj;
    
    // accepting article details from user
    cout << "Enter the priority of the article : ";
    cin >> newArticleObj.priorityNum;
    
    cout << "Enter the Headline : ";
    cin.ignore();
    getline(cin, newArticleObj.headline);
    
    cout << "Enter the body of the article : ";
    cin.ignore();
    getline(cin, newArticleObj.article);
    
    return newArticleObj;
}

// finds the position of first article with given priority
int newsWebsite::positionFinder(int x)
{
    // loop through all articles
    for (int i = 0; i < lastArticle; i++)
    {
        // return position when priority matches
        if (x == nw[i].priorityNum)
        {
            int x;
            return i;
        }
    }
}

// pushes all articles from position x onwards one position forward
void newsWebsite::pushArticleFromPos(int x)
{
    // temporary array to store current articles
    newsArticle temp[maxArticlesSize];
    
    // copy all articles to temp array
    for (int i = 0; i < lastArticle; i++)
    {
        temp[i] = nw[i];
    }
    
    // if inserting at beginning
    if (x == 0)
    {
        // shift all articles one position forward
        for (int i = 0; i < lastArticle; i++)
        {
            nw[i + 1] = temp[i];
        }
    }
    else
    {
        // shift articles from position x onwards
        for (int i = x; i < lastArticle; i++)
        {
            nw[i + 1] = temp[i];
        }
    }
    
    // increment last article counter
    lastArticle++;
}

// inserts article at correct position based on priority
void newsWebsite::insertArticle(newsArticle newArticle)
{
    // if breaking news (priority 0), insert at beginning
    if (newArticle.priorityNum == 0)
    {
        pushArticleFromPos(0);
        nw[0] = newArticle;
    }
    // for other priorities, find correct position
    else if (newArticle.priorityNum >= 1)
    {
        int pos;
        
        // switch case to handle different priority levels
        switch (newArticle.priorityNum)
        {
        case 0:
            pushArticleFromPos(0);
            nw[0] = newArticle;
            break;
        case 1:
            pos = positionFinder(1);
            pushArticleFromPos(pos);
            nw[pos] = newArticle;
            break;
        case 2:
            pos = positionFinder(2);
            pushArticleFromPos(pos);
            nw[pos] = newArticle;
            break;
        case 3:
            pos = positionFinder(3);
            pushArticleFromPos(pos);
            nw[pos] = newArticle;
            break;
        case 4:
            pos = positionFinder(4);
            pushArticleFromPos(pos);
            nw[pos] = newArticle;
            break;
        case 5:
            pos = positionFinder(5);
            pushArticleFromPos(pos);
            nw[pos] = newArticle;
        default:
            break;
        }
    }
}

// converts string news type to integer priority (overloaded function)
int newsWebsite::priorityDecider(string newsType)
{
    // defining priority types
    string breaking = "breaking";
    string international = "international";
    string national = "national";
    string state = "state";
    string local = "local";
    
    // compare and return appropriate priority number
    if (strcmp(newsType.c_str(), breaking.c_str()) == 0)
    {
        return 1;
    }
    else if (strcmp(newsType.c_str(), international.c_str()) == 0)
    {
        return 2;
    }
    else if (strcmp(newsType.c_str(), national.c_str()) == 0)
    {
        return 3;
    }
    else if (strcmp(newsType.c_str(), state.c_str()) == 0)
    {
        return 4;
    }
    else if (strcmp(newsType.c_str(), local.c_str()) == 0)
    {
        return 5;
    }
}

// converts integer priority to string news type (overloaded function)
string newsWebsite::priorityDecider(int newsType)
{
    // defining priority types
    string breaking = "breaking";
    string international = "international";
    string national = "national";
    string state = "state";
    string local = "local";

    // switch case to return string based on priority number
    switch (newsType)
    {
    case 1:
        return breaking;
        break;
    case 2:
        return international;
        break;
    case 3:
        return national;
        break;
    case 4:
        return state;
        break;
        int x;
    case 5:
        return local;
        break;
    default:
        return "idk what this is ";
        break;
    }
}

// loads articles from CSV file into array
void newsWebsite::loadCSV(string csvFile)
{
    // open the CSV file
    ifstream file(csvFile);
    
    // check if file opened successfully
    if (!file.is_open())
    {
        cout << "ERROR OPENING FILE" << endl;
        return;
    }
    
    string t;
    int i = 0;
    
    // read file line by line
    while (getline(file, t) && i < maxArticlesSize)
    {
        // use stringstream to parse CSV line
        stringstream ss(t);
        string priority, headline, body;

        // extract comma separated values
        getline(ss, priority, ',');
        getline(ss, headline, ',');
        getline(ss, body, ',');

        // store article in array
        nw[i].priorityNum = priorityDecider(priority);
        nw[i].headline = headline;
        nw[i].article = body;
        i++;
        lastArticle = i;
    }
    
    // close the file
    file.close();
    cout << "Data ingested from " << csvFile << endl;
    return;
}

// saves all articles to CSV file
void newsWebsite::saveToCSV(string csvFile)
{
    // open file in write mode
    ofstream file(csvFile);
    
    // check if file opened successfully
    if (!file.is_open())
    {
        cout << "ERROR OPENING FILE" << endl;
        return;
    }
    
    // loop through all articles and write to file
    for (int i = 0; i < lastArticle; i++)
    {
        file << priorityDecider(nw[i].priorityNum) << ",";
        file << nw[i].headline << ",";
        file << nw[i].article << "\n";
    }
    
    // close the file
    file.close();
    cout << "Data saved to : " << csvFile << endl;
}

int main()
{
    // creating news website object and loading CSV file
    newsWebsite nWebsite("csvFileIngest.csv");
    
    // variable to control while loop
    int isOver = 1;
    int switchCaseDecider;
    int x;
    
    // main loop for user operations
    while (isOver == 1)
    {
        // display all articles
        nWebsite.displayAllArticles();
        
        // display menu options
        cout << "-----------------------OPERATIONS-----------------------" << endl;
        cout << "\t1.Delete an article\n\t2.Insert an article\n\t3.Deleting based on priority\n\t4.Exit" << endl;
        cout << "Enter operation : ";
        cin >> switchCaseDecider;
        
        // perform operation based on user choice
        switch (switchCaseDecider + 1)
        {
        case 1:
            // display all articles
            nWebsite.displayAllArticles();
            break;
        case 2:
            // delete article at specific position
            cout << "Article at what position is to be deleted : ";
            cin >> x;
            nWebsite.deleteArticle(x - 1);
            break;
        case 3:
            // insert a new article
            nWebsite.insertArticle(nWebsite.newArticle());
            break;
        case 4:
            // delete all breaking news articles
            nWebsite.deleteBasedOnPriority();
            break;
        case 5:
            // exit the program
            isOver = 0;
            break;
        default:
            // invalid operation
            cout << "INVALID OPERATION!!!" << endl;
            break;
        }

        // ask user if they want to continue
        cout << endl
             << "Do you want to continue ? (1 to continue, any other integer to end) : ";
        cin >> isOver;
    }

    // save all articles to output CSV file before exiting
    nWebsite.saveToCSV("csvFileOutput.csv");
    return 0;
}