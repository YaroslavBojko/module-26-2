#include <string>
#include <iostream>
#include <vector>

class Number
{
public:
    std::string numberCheck()
    {
        bool right = false;
        std::string number;

        while (!right)
        {
            std::cout << "Enter phone number: ";
            std::cin >> number;

            if (number.size() != 12 || number[0] != '+' || number[1] != '7')
                std::cout << "Wrong phone number!!!" << std::endl;
            else
            {
                right = true;
                return number;
            }
        }
    }
};

class Contact
{
public:
    std::string number;
    std::string name;
    int i = 0;

    void addContact(std::vector<Contact*> contactBook)
    {
        Number* number1 = new Number;
        contactBook[i]->number = number1->numberCheck();

        std::string name;
        std::cout << "Enter name: ";
        std::cin >> name;
        contactBook[i]->name = name;
        i++;
        delete number1;
    }
};

class Phone
{
    std::vector<Contact*> contactBook;
    Contact* contact = new Contact;

    public:
    void add()
    {
        contactBook.push_back(new Contact());
        contact->addContact(contactBook);
    }

    void call()
    {
        std::string input;
        std::cout << "Enter a contact name or phone number: ";
        std::cin >> input;

        std::cout << "   CALL    " << std::endl;
        if(input[0] == '+' && input[1] == '7')
        {
            for (int i = 0; i < contactBook.size(); ++i)
            {
                if (input == contactBook[i]->number)
                    std::cout << contactBook[i]->name << std::endl;
            }
            std::cout << input << std::endl;
        }
        else
        {
            bool found = false;
            for (int i = 0; i < contactBook.size(); ++i)
            {
                if (input == contactBook[i]->name)
                {
                    std::cout << contactBook[i]->name << std::endl;
                    std::cout << contactBook[i]->number << std::endl;
                    found = true;
                    break;
                }
            }
            if (!found) std::cout << "This contact was not found!!!" << std::endl;
        }
    }

    void message()
    {
        std::string input;
        std::cout << "Enter a contact name or phone number: ";
        std::cin >> input;

        if(input[0] == '+' && input[1] == '7')
        {
            std::string message;
            std::cout << "Enter your message: ";
            std::cin >> message;

            std::cout << "   Message!!!" << std::endl;
            std::cout << input << std::endl;
            std::cout << message << std::endl;
        }
        else
        {
            bool found = false;
            for (int i = 0; i < contactBook.size(); ++i)
            {
                if (input == contactBook[i]->name)
                {
                    found = true;
                    break;
                }
            }
            if (!found) std::cout << "This contact was not found!!!" << std::endl;
            if (found)
            {
                std::string message;
                std::cout << "Enter your message: ";
                std::cin >> message;

                std::cout << "   Message!!!" << std::endl;
                std::cout << input << std::endl;
                std::cout << message << std::endl;
            }
        }
    }

};

int main()
{
    Phone* phone = new Phone;
    std::string command;

    while (command != "exit")
    {
        std::cout << "Command (add, call, sms, exit): ";
        std::cin >> command;

        if (command == "add") phone->add();

        if (command == "call") phone->call();

        if (command == "sms") phone->message();

    }
    delete phone;

}
