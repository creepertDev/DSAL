// 23303
// To implement and demonstrate the working of a Priority Queue and a Double-Ended Queue (Deque) supporting standard operations such as insertion, deletion, and display.
// news website management system

#include <iostream>
#include <cstring>
using namespace std;
#define maxArticlesSize 15
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <iomanip>

struct newsArticle
{
    int priorityNum;
    string headline;
    string article;
};

typedef struct newsArticle newsArticle;

class newsWebsite
{
private:
    newsArticle nw[maxArticlesSize];
    int lastArticle;

public:
    newsArticle newArticle();
    int priorityDecider(string newsType);
    string priorityDecider(int newsType);
    void loadCSV(string csvFile);
    void saveToCSV(string csvFile);
    void insertArticle(newsArticle newArticle);
    void pushArticleFromPos(int x);
    int positionFinder(int x);
    void deleteArticle(int x);
    void displayAllArticles();
    void deleteBasedOnPriority();

    newsWebsite(string csvFile)
    {
        loadCSV(csvFile);
    }
};

void newsWebsite::deleteBasedOnPriority()
{
    int x = 0;
    while (nw[x].priorityNum == 1)
    {
        deleteArticle(x);
    }
    return;
}

void newsWebsite::displayAllArticles()
{
    system("clear");
    cout << "                                           XYZ NEWS" << endl;
    int x = 0;
    while (x != lastArticle)
    {
        cout << x + 1 << " . " << priorityDecider(nw[x].priorityNum) << " : " << nw[x].headline << endl
             << nw[x].article << "\n"
             << endl;
        x++;
    }
    return;
}

void newsWebsite::deleteArticle(int x)
{
    int y = x;
    while (y != lastArticle)
    {
        nw[y] = nw[y + 1];
        y++;
    }

    lastArticle--;
    return;
}

newsArticle newsWebsite::newArticle()
{
    newsArticle newArticleObj;
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

int newsWebsite::positionFinder(int x)
{
    for (int i = 0; i < lastArticle; i++)
    {
        if (x == nw[i].priorityNum)
        {
            int x;
            return i;
        }
    }
}

void newsWebsite::pushArticleFromPos(int x)
{
    newsArticle temp[maxArticlesSize];
    for (int i = 0; i < lastArticle; i++)
    {
        temp[i] = nw[i];
    }
    if (x == 0)
    {
        for (int i = 0; i < lastArticle; i++)
        {
            nw[i + 1] = temp[i];
        }
    }
    else
    {
        for (int i = x; i < lastArticle; i++)
        {
            nw[i + 1] = temp[i];
        }
    }
    lastArticle++;
}
void newsWebsite::insertArticle(newsArticle newArticle)
{
    if (newArticle.priorityNum == 0)
    {
        pushArticleFromPos(0);
        nw[0] = newArticle;
    }
    else if (newArticle.priorityNum >= 1)
    {
        int pos;
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

int newsWebsite::priorityDecider(string newsType)
{
    string breaking = "breaking";
    string international = "international";
    string national = "national";
    string state = "state";
    string local = "local";
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

string newsWebsite::priorityDecider(int newsType)
{
    string breaking = "breaking";
    string international = "international";
    string national = "national";
    string state = "state";
    string local = "local";

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

void newsWebsite::loadCSV(string csvFile)
{
    ifstream file(csvFile);
    if (!file.is_open())
    {
        cout << "ERROR OPENING FILE" << endl;
        return;
    }
    string t;
    int i = 0;
    while (getline(file, t) && i < maxArticlesSize)
    {
        stringstream ss(t);
        string priority, headline, body;

        getline(ss, priority, ',');
        getline(ss, headline, ',');
        getline(ss, body, ',');

        nw[i].priorityNum = priorityDecider(priority);
        nw[i].headline = headline;
        nw[i].article = body;
        i++;
        lastArticle = i;
    }
    file.close();
    cout << "Data ingested from " << csvFile << endl;
    return;
}

void newsWebsite::saveToCSV(string csvFile)
{
    ofstream file(csvFile);
    if (!file.is_open())
    {
        cout << "ERROR OPENING FILE" << endl;
        return;
    }
    for (int i = 0; i < lastArticle; i++)
    {
        file << priorityDecider(nw[i].priorityNum) << ",";
        file << nw[i].headline << ",";
        file << nw[i].article << "\n";
    }
    file.close();
    cout << "Data saved to : " << csvFile << endl;
}

int main()
{
    newsWebsite nWebsite("csvFileIngest.csv");
    int isOver = 1;
    int switchCaseDecider;
    int x;
    while (isOver == 1)
    {
        nWebsite.displayAllArticles();
        cout << "-----------------------OPERATIONS-----------------------" << endl;
        cout << "\t1.Delete an article\n\t2.Insert an article\n\t3.Deleting based on priority\n\t4.Exit" << endl;
        cout << "Enter operation : ";
        cin >> switchCaseDecider;
        switch (switchCaseDecider + 1)
        {
        case 1:
            nWebsite.displayAllArticles();
            break;
        case 2:
            cout << "Article at what position is to be deleted : ";
            cin >> x;
            nWebsite.deleteArticle(x - 1);
            break;
        case 3:
            nWebsite.insertArticle(nWebsite.newArticle());
            break;
        case 4:
            nWebsite.deleteBasedOnPriority();
            break;
        case 5:
            isOver = 0;
            break;
        default:
            cout << "INVALID OPERATION!!!" << endl;
            break;
        }

        cout << endl
             << "Do you want to continue ? (1 to continue, any other integer to end) : ";
        cin >> isOver;
    }

    nWebsite.saveToCSV("csvFileOutput.csv");
    return 0;
}