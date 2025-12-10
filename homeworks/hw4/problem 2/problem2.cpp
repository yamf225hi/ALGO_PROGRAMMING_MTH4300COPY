#include <iostream>
#include <stack>
#include <string>
#include <vector>

void print_text(std::stack<std::string> history) 
{
    std::vector<std::string> words;
    while (!history.empty()) 
    {
        words.push_back(history.top());
        history.pop();
    }

    std::cout << "Text: ";
    for (int i = words.size() - 1; i >= 0; --i) 
    {
        std::cout << words[i] << " ";
    }
    std::cout << std::endl;
}

int main() 
{
    std::stack<std::string> history;
    std::string command, word;

    while (std::cin >> command) 
    {
        if (command == "TYPE") 
        {
            std::cin >> word;
            history.push(word);
        } else if (command == "UNDO") 
        {
            if (!history.empty()) 
            {
                history.pop();
            }
        }
    }

    std::stack<std::string> temp;
    while(!history.empty())
    {
        temp.push(history.top());
        history.pop();
    }

    std::cout << "Text: ";
    while(!temp.empty())
    {
        std::cout << temp.top() << " ";
        temp.pop();
    }
    std::cout << std::endl;


    return 0;
}