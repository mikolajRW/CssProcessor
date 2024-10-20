#include <iostream>
#include <stdio.h>
#include<cstring>
#include "my_own_string.h"

#define SIZE_OF_ARRAY_OF_STRUCTURES 8
#define ASCI_OF_SPACE 32
#define ASCI_OF_ENTER 13
#define ASCI_OF_CHAR 11
#define ASCI_OF_ANOTHER_CHAR 12
#define ADD_ATTRibute 1
#define ADD_SELECTOR 0
#define ADD_VALUE_OF_ATTRIBUTE 2
#define ADD_ROOT 3
#define CREATE_A_NEW_STRING 4

using namespace std;


template<typename T>
class DoubleList {
    struct Node {
        T data[SIZE_OF_ARRAY_OF_STRUCTURES];
        bool valid_data[SIZE_OF_ARRAY_OF_STRUCTURES]; //which_elements_in_particular_array_are_taken
        int size = 0;
        Node* next;
        Node* prev;
    };

    Node* head;
    int counter;
    short counter_of_all_elements;

    int GetUltimateSize() {
        Node* curr = GetNode(counter - 1); //gets pointer of last node in list

        if (curr == nullptr)
        {
            return 0;
        }

        return (((counter - 1) * SIZE_OF_ARRAY_OF_STRUCTURES) + curr->size); //calculate number of elements in all arrays;
    }

    Node* GetNode(int index) {
        if (index >= counter || index < 0)
        {
            return nullptr;
        }

        Node* curr = head;

        for (int i = 0; i < index; i++)
        {
            curr = curr->next;
        }

        return curr;
    }

    int AddToArray(Node* curr, T dataToFunction) {
        if (curr->size == SIZE_OF_ARRAY_OF_STRUCTURES)
        {
            return 1;
        }

        curr->data[curr->size] = dataToFunction;
        curr->valid_data[curr->size] = true;
        curr->size++;
        counter_of_all_elements++;
        return 0;
    }

    int DeleteFromArray(Node* curr, int index) {
        if (curr->size == 0)
        {
            return 1;
        }
        curr->valid_data[index] = false;
        return 0;
    }

    int isArrayEmpty(Node* curr)
    {
        for (int i = 0; i < SIZE_OF_ARRAY_OF_STRUCTURES; i++) {
            if (curr->valid_data[i] == true)
            {
                return 0;
            }
        }

        return 1;
    }

public:
    DoubleList() {
        head = nullptr;
        counter = 0;
        counter_of_all_elements = 0;
    }
    void clear_list() {
        Node* curr = head;
        while (curr != nullptr)
        {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }

    Node* get_head()
    {

        return head;
    }

    void Add(T data) {
        if (head == nullptr)
        {
            head = new Node;
            head->prev = nullptr;
            head->next = nullptr;
            AddToArray(head, data);
            counter++;
            counter_of_all_elements++;
        }
        else
        {
            Node* curr = head;

            while (curr->next != nullptr)
            {
                curr = curr->next;
            }

            if (AddToArray(curr, data))
            {
                curr->next = new Node;
                curr->next->prev = curr;
                curr->next->next = nullptr;
                AddToArray(curr->next, data);
                counter++;
                counter_of_all_elements++;
            }
        }

    }

    void Delete(int index) { //index starts with 0
        int ultimate_size = GetUltimateSize();

        if (index >= counter_of_all_elements) {
            return;
        }

        int node_index = (index / SIZE_OF_ARRAY_OF_STRUCTURES);
        int index_in_array = index % SIZE_OF_ARRAY_OF_STRUCTURES;
        Node* curr = GetNode(node_index);
        if (curr == nullptr)
        {
            return;
        }
        curr->valid_data[index_in_array] = false;
        curr->size--;
        counter_of_all_elements--;

        // If the current node is empty, remove it
        if (curr->size == 0) {
            if (curr->prev != nullptr) {
                curr->prev->next = curr->next;
            }
            if (curr->next != nullptr) {
                curr->next->prev = curr->prev;
            }
            if (curr == head) {
                head = curr->next;
            }
            delete curr;
            counter--;
        }
    }
    int Size() {
        return GetUltimateSize();
    }

    T* Get(int index) {
        if (index >= GetUltimateSize())
        {
            return nullptr;
        }

        int node_index = (index / SIZE_OF_ARRAY_OF_STRUCTURES);
        Node* curr = GetNode(node_index);

        if (isArrayEmpty(curr))
        {
            return nullptr;
        }

        if (curr->valid_data[index % SIZE_OF_ARRAY_OF_STRUCTURES])
        {
            return &curr->data[index % SIZE_OF_ARRAY_OF_STRUCTURES];
        }

        return nullptr;
    }
    short get_counter_of_all_elements()
    {
        return counter_of_all_elements;
    }
    void show() //zrob funkcje
    {
        short count = 0;
        while (head != nullptr)
        {
            if (counter % SIZE_OF_ARRAY_OF_STRUCTURES + 1 < count)
            {
                break;
            }
            cout << head->data[count] << " ";
            count++;
            if (head->size == SIZE_OF_ARRAY_OF_STRUCTURES)
            {
                count = 0;
                head = head->next;
            }
        }
    }

};


class Simple_list {
    struct Node {
        My_own_string data;
        Node* next;
        Node* prev;
    };
    Node* head;
    short counter;

public:
    Simple_list()
    {
        head = nullptr;
        counter = 0;
    }

    bool check_if_this_element_was(My_own_string data_to_check)
    {
        Node* curr = head;
        while (curr != nullptr)
        {
            if (strcmp(curr->data.my_string, data_to_check.my_string) == 0)
            {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }
    void adding_in_simpler_list(My_own_string data_in_function)
    {
        if (head == nullptr)
        {
            head = new Node;
            head->next = nullptr;
            head->data = data_in_function;
            counter++;
        }
        else

        {
            Node* curr = head;

            while (curr->next != nullptr)
            {
                curr = curr->next;
            }

            curr->next = new Node;
            curr->next->prev = curr;
            curr->next->next = nullptr;
            curr->next->data = data_in_function;
            counter++;
        }
    }

    short IsEmpty() {
        if (head == nullptr);
        {
            return 1;
        }
        return 0;
    }
    short get_counter()
    {
        return counter;
    }
    Node* Get_head()
    {
        Node* curr = head;
        return curr;
    }

    void go_to_the_next_element()
    {
        head = head->next;
    }
    My_own_string Get_data_from_head()
    {
        Node* curr = head;
        return curr->data;
    }

    My_own_string Get(short index)
    {
        if (index > counter)
        {
            return 0;
        }
        Node* tmp = head;
        for (int i = 0; i < index; i++)
        {
            tmp = tmp->next;
        }
        return tmp->data;
    }

    void remove_by_index(short index)
    {
        if (head == NULL) {
            return;
        }

        Node* temp = head;

        if (index == 0) {
            head = temp->next;
            if (head != NULL) {
                head->prev = NULL;
            }
            delete temp;
            return;
        }

        for (int i = 0; temp != NULL && i < index - 1; i++) {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL) {
            return;
        }

        Node* next = temp->next->next;
        delete temp->next;
        temp->next = next;

        if (next != NULL) {
            next->prev = temp;
        }
    }

    bool Get_index_of_last_give_element(My_own_string string_in_function)
    {
        short counter = 0;
        Node* curr = head;
        while (curr != nullptr)
        {
            if (strcmp(curr->data.my_string, string_in_function.my_string) == 0)
            {
                return true;
            }
            curr = curr->next;
            counter++;
        }
        return false;
    }


    bool how_many_times_one_element(My_own_string string_in_function)
    {
        short counter = 0;
        Node* curr = head;
        while (curr != nullptr)
        {
            if (strcmp(curr->data.my_string, string_in_function.my_string) == 0)
            {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    short find_index(My_own_string string_in_function) {
        short counter = 0;
        Node* curr = head;
        while (curr != nullptr)
        {
            if (strcmp(curr->data.my_string, string_in_function.my_string) == 0)
            {
                return counter;
            }
            curr = curr->next;
            counter++;
        }
        return -5;
    }

    void clear_list()
    {
        while (head != nullptr)
        {
            Node* curr = head;
            head = head->next;
            delete curr;
            counter--;
        }
    }


};

class list_of_int {
    struct Node {
        Node* next;
        short data = 0;
    };
    Node* Head;
    short counter;
public:
    list_of_int()
    {
        Head = nullptr;
        counter = 0;
    }
    void add_new_element(short data_in_function)
    {
        if (Head == nullptr)
        {
            Head = new Node;
            Head->next = nullptr;
            Head->data = data_in_function;
            counter++;
        }
        else
        {
            Node* curr = Head;
            while (curr->next != nullptr)
            {
                curr = curr->next;
            }
            curr->next = new Node;
            curr->next->data = data_in_function;
            curr->next->next = nullptr;
            counter++;
        }
    }
    short show_particular_element(short index)
    {
        if (index > counter || index < 0)
        {
            return -10;
        }
        Node* tmp = Head;
        for (int i = 0; i < index; i++)
        {
            tmp = tmp->next;
        }
        return tmp->data;
    }
    short get_counter()
    {
        return counter;
    }

    int getElementAt(int index) {
        Node* current = Head;
        int count = 0;
        while (current != NULL) {
            if (count == index) {
                return current->data;
            }
            count++;
            current = current->next;
        }
        return -1;
    }
    void remove(int index) {
        Node* current = Head;
        Node* previous = nullptr;
        int count = 0;

        if (index == 0) {
            Node* temp = Head;
            Head = Head->next;
            delete temp;
            return;
        }

        while (current != nullptr && count != index) {
            previous = current;
            current = current->next;
            count++;
        }

        if (current == nullptr) {
            return;
        }

        previous->next = current->next;
        delete current;
    }

    void decreament(short index)
    {
        if (index > counter)
        {
            return;
        }
        Node* curr = Head;
        for (int i = 0; i < index; i++)
        {
            curr = curr->next;
        }

        curr->data--;
    }

    void clear_list()
    {
        Node* curr = Head;
        while (curr != nullptr)
        {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

};
struct Section {
    Simple_list selectors;
    Simple_list atrybuties;
    Simple_list values;
};

struct bools_using_in_programm {
    bool input_mode;
    bool read_CSS_file;
    bool commands;
    bool add_atributes;
};



std::ostream& operator<<(std::ostream& ostr, const My_own_string& string)
{
    ostr << string.my_string;
    return ostr;
}

istream& operator>> (istream& in, My_own_string& string)
{

    char* buff = new char[1000];
    memset(&buff[0], 0, sizeof(buff));
    in >> buff;
    string = My_own_string{ buff };
    delete[] buff;
    return in;

}


//Functions responsible for commands


void check_if_we_still_adding_css_file(bool& css_adding, bool& add_section)
{
    if (css_adding == true)
    {
        add_section = true;
    }
}


void del_ws(char* word) {
    int len = 0;

    for (len; word[len] != '\0'; len++) {}

    if (word[len - 1] != ASCI_OF_SPACE && word[len - 1] != '\n' && word[len - 1] != '\t' && word[len - 1] != ASCI_OF_ANOTHER_CHAR && word[len - 1] != ASCI_OF_ENTER && word[len - 1] != ASCI_OF_CHAR)
        return;

    for (int i = 1; i < len; i++)
    {
        if (word[len - i - 1] != 32 && word[len - i - 1] != '\n' && word[len - i - 1] != '\t' && word[len - 1] != ASCI_OF_ANOTHER_CHAR && word[len - 1] != ASCI_OF_ENTER && word[len - 1] != ASCI_OF_CHAR)
        {
            word[len - i] = '\0';
            break;
        }
    }
}

short read_Input_CSS(char* word, short flags, bools_using_in_programm& bools)
{
    bool is_white_space = true;
    int key = 0;
    int len = 0;
    while (key != '\n')  //to jeszcze do ustalenia co najelpsze
    {
        key = getchar();
        if (is_white_space)
        {
            if (key == ' ' || key == '\n' || key == '\t' || key == ASCI_OF_ANOTHER_CHAR || key == ASCI_OF_CHAR || key == ASCI_OF_ENTER)
            {
                continue;
            }
            is_white_space = false;
        }
        /*
        */
        word[len] = key;

        if (flags == 0)//selecotrs
        {
            if (word[len] == ',')
            {

                len++;
                word[len - 1] = 0;
                return ADD_SELECTOR;
            }
            if (word[len] == '{')
            {

                bools.add_atributes = false;
                len++;
                word[len - 1] = 0;
                return ADD_SELECTOR;
            }

        }

        if (flags == 1)
        {
            if (word[0] == '}')
            {
                len++;
                word[len - 1] = 0;

                return ADD_ROOT;
            }
            if (word[len] == ':')
            {

                len++;
                word[len - 1] = 0;
                return ADD_ATTRibute;
            }
        }

        if (flags == 2)
        {
            if (word[len] == ';')
            {
                len++;
                word[len - 1] = 0;


                return ADD_VALUE_OF_ATTRIBUTE;
            }


        }

        if (flags != 2 && is_white_space)
        {
            if (word[len] == ' ' || word[len] == '\n' || word[len] == '\t' || word[len] == ASCI_OF_ANOTHER_CHAR || word[len] == ASCI_OF_CHAR || word[len] == ASCI_OF_ENTER)
            {
                word[len] = '\0';
                len--;
            }
            else
            {
                is_white_space = false;
            }
        }
        len++;
        /*
        */

    }

    len++;
    word[len - 1] = 0;
    if (flags == 1)
    {
        return 2;
    }
    if (flags == 2)
    {
        return 1;
    }

    return 0;
}


void changing_flags(short& flags, bools_using_in_programm& bools)
{

    if (bools.add_atributes == true)
    {
    }
    else if (bools.add_atributes == false)
    {
        flags = ADD_ATTRibute;
        bools.add_atributes = true;
        return;
    }

    if (flags == ADD_ATTRibute)
    {
        flags = ADD_VALUE_OF_ATTRIBUTE;
    }
    else if (flags == ADD_VALUE_OF_ATTRIBUTE)
    {
        flags = ADD_ATTRibute;
    }
}

bool read_CSS(short& flags, DoubleList<Section>& roots, bools_using_in_programm& bools, short& number_of_nodes, list_of_int& how_many_selectors_in_particular_root, list_of_int& how_many_atributes_in_particular_root)
{
    bool add_section = false;
    char word[200];
    while (1 > 0)
    {
        short counter = 0;
        short counter_of_attributes = 0;
        Section one_element_in_array;
        add_section = false;
        while (add_section != true)
        {

            flags = read_Input_CSS(word, flags, bools);
            del_ws(word);
            My_own_string string;
            if (flags != CREATE_A_NEW_STRING)
            {
                string = word;
            }
            if (strcmp(string.my_string, "????") == 0)
            {
                bools.commands = true;
                bools.read_CSS_file = false;
                return true;
            }
            //if (strcmp(string.my_string, "") == 0)
            //{
            //      return false;
            //}
            if (flags == ADD_SELECTOR)
            {
                if (strcmp(string.my_string, "") == 0)
                {

                }
                else if (strcmp(string.my_string, "????") == 0)
                {
                    bools.read_CSS_file = false;
                    bools.commands = true;
                    break;
                }
                else
                {

                    one_element_in_array.selectors.adding_in_simpler_list(string);
                    counter++;
                }
            }
            if (flags == ADD_ATTRibute)
            {
                if (strcmp(string.my_string, "") == 0)
                {

                }
                else if (one_element_in_array.atrybuties.check_if_this_element_was(string) == true)
                {
                    short index_of_the_same_argument = one_element_in_array.atrybuties.find_index(string);
                    one_element_in_array.atrybuties.remove_by_index(index_of_the_same_argument);
                    one_element_in_array.values.remove_by_index(index_of_the_same_argument);
                    one_element_in_array.atrybuties.adding_in_simpler_list(string);
                }
                else
                {
                    one_element_in_array.atrybuties.adding_in_simpler_list(string);
                    counter_of_attributes++;

                }
            }
            if (flags == ADD_VALUE_OF_ATTRIBUTE)
            {
                if (strcmp(string.my_string, "") == 0)
                {

                }
                else
                {
                    one_element_in_array.values.adding_in_simpler_list(string);
                }
            }
            if (flags == ADD_ROOT)
            {
                roots.Add(one_element_in_array);
                how_many_selectors_in_particular_root.add_new_element(counter);
                how_many_atributes_in_particular_root.add_new_element(counter_of_attributes);
                add_section = true;
                flags = ADD_SELECTOR;
                number_of_nodes++;
            }
            changing_flags(flags, bools);
        }
    }
    return true;

}




void set_lenght(Simple_list commands, short& len)
{
    while (commands.Get_data_from_head().my_string[len] != ',' && commands.Get_data_from_head().my_string[len] != '\0')
    {
        len++;
    }
}
void set_first_part_of_the_command(char* char_number, short len, Simple_list commands)
{
    for (int i = 0; i < len; i++)
    {
        char_number[i] = commands.Get_data_from_head().my_string[i];
    }
}
void command_number_S_or_A_question_mark(DoubleList<Section> roots, list_of_int how_many_elements_in_particular_root, short number, char command)
{
    if (roots.get_head() == nullptr)
    {

    }
    else if (roots.Get(number - 1) == nullptr)
    {

    }
    else
    {
        cout << number << "," << command << ",? == " << how_many_elements_in_particular_root.show_particular_element(number - 1) << endl;;
    }
}

void command_number_S_number(short len, Simple_list commands, DoubleList<Section> roots, short number, list_of_int List_of_selec)
{

    short lenght = len + 3;
    while (commands.Get_data_from_head().my_string[lenght] != 0)
    {
        lenght++;
    }
    char* char_nbr = new char[lenght - len + 3];
    for (int i = 0; i < lenght - len + 3; i++)
    {
        char_nbr[i] = commands.Get_data_from_head().my_string[len + 3 + i];
    }
    short nbr = atoi(char_nbr);

    if (roots.Get(number - 1) == nullptr)
    {

    }
    else
    {
        if (List_of_selec.show_particular_element(number - 1) < nbr)
        {

        }
        else
        {

            cout << number << ",S," << nbr << " == " << roots.Get(number - 1)->selectors.Get(nbr - 1) << endl;
        }
    }
}

void command_number_A_atribute(short len, Simple_list commands, DoubleList<Section> roots, short number, Section section)
{
    short lenght = len + 3;
    while (commands.Get_data_from_head().my_string[lenght] != 0)
    {
        lenght++;
    }
    char* char_nbr = new char[lenght - len + 3];
    for (int i = 0; i < lenght - len + 3; i++)
    {
        char_nbr[i] = commands.Get_data_from_head().my_string[len + 3 + i];
    }
    My_own_string tmp = char_nbr;

    if (roots.Get(number - 1) == nullptr)
    {

    }
    else
    {

        short index_of_value = roots.Get(number - 1)->atrybuties.find_index(tmp);
        if (index_of_value != -5)
        {
            if (strcmp(roots.Get(number - 1)->values.Get(index_of_value).my_string, "") != 0)
            {
                cout << number << ",A," << tmp << " == " << roots.Get(number - 1)->values.Get(index_of_value) << endl;
            }
        }
    }
}

void command_attribute_A_question_mark(short len, DoubleList<Section> roots, Simple_list commands, short number_of_nodes)
{
    char* test = new char[len];
    for (int i = 0; i < len; i++)
    {
        test[i] = commands.Get_data_from_head().my_string[i];
    }
    test[len] = 0;
    My_own_string tmp = test;
    short counter = 0;
    for (int i = 0; i < number_of_nodes; i++)
    {
        if (roots.Get(i) != nullptr)
        {
            counter += roots.Get(i)->atrybuties.how_many_times_one_element(tmp);
        }
        else
        {
            break;
        }
    }
    cout << tmp << ",A,? == " << counter << endl;
}

void command_selector_S_question_mark(short len, DoubleList<Section> roots, Simple_list commands, short numbeR_of_nodes)
{

    char* test = new char[len];
    for (int i = 0; i < len; i++)
    {
        test[i] = commands.Get_data_from_head().my_string[i];
    }
    test[len] = 0;
    My_own_string tmp = test;
    short counter = 0;
    for (int i = 0; i < numbeR_of_nodes; i++)
    {
        if (roots.Get(i) != nullptr)
        {
            counter += roots.Get(i)->selectors.how_many_times_one_element(tmp);
        }
        else
        {
            break;
        }
    }


    cout << tmp << ",S,? == " << counter << endl;
}



void command_selector_E_attribute(char* char_number, short len, Simple_list commands, DoubleList<Section> roots, short number_of_nodes)
{
    set_first_part_of_the_command(char_number, len, commands);
    char_number[len] = 0;
    My_own_string tmp_Selec = char_number;
    short lenght = len + 3;
    while (commands.Get_data_from_head().my_string[lenght] != 0)
    {
        lenght++;
    }
    char* char_nbr = new char[lenght - len + 3];
    for (int i = 0; i < lenght - len + 3; i++)
    {
        char_nbr[i] = commands.Get_data_from_head().my_string[len + 3 + i];
    }
    My_own_string tmp_attr = char_nbr;
    short index;
    short index_of_value;
    short index_of_root = -1;
    short save_index = 0;
    for (int i = 0; i < number_of_nodes; i++)
    {
        if (roots.Get(i) != nullptr)
        {

            if (roots.Get(i)->selectors.how_many_times_one_element(tmp_Selec) == true)
            {
                index_of_root++;
                save_index = number_of_nodes - i;
            }
            else
            {
                index_of_root++;
            }
        }
        else
        {

        }
    }

    index_of_root = number_of_nodes - save_index;

    if (index_of_root != -1 && roots.Get(index_of_root) != nullptr)
    {
        index_of_value = roots.Get(index_of_root)->atrybuties.find_index(tmp_attr);
        if (index_of_value != -5)
        {
            cout << tmp_Selec << ",E," << tmp_attr << " == " << roots.Get(index_of_root)->values.Get(index_of_value) << endl;
        }
    }
}









void exec_commands(Simple_list& commands, short& number_of_nodes, DoubleList<Section>& roots, list_of_int& how_many_selectors_in_particular_root, Section& section, list_of_int& how_many_atributes_in_particular_root)
{
    int number;
    short helpful = 0;
    while (commands.Get_head() != nullptr)
    {

        if (strcmp(commands.Get_data_from_head().my_string, "?") == 0)
        {
            cout << "? == " << number_of_nodes << endl;
        }
        else if (strcmp(commands.Get_data_from_head().my_string, "****") == 0)
        {

        }
        else {
            char command;
            short len = 0;
            set_lenght(commands, len);
            command = commands.Get_data_from_head().my_string[len + 1];
            char* char_number = new char[len - 1];
            if (command == 'S')
            {

                set_first_part_of_the_command(char_number, len, commands);
                if (char_number[0] >= '0' && char_number[0] <= '9')
                {

                    number = atoi(char_number);
                    if (commands.Get_data_from_head().my_string[len + 3] == '?')
                    {
                        command_number_S_or_A_question_mark(roots, how_many_selectors_in_particular_root, number, command);
                    }
                    else
                    {

                        command_number_S_number(len, commands, roots, number, how_many_selectors_in_particular_root);
                    }
                }
                else
                {
                    command_selector_S_question_mark(len, roots, commands, number_of_nodes);
                }
            }
            else if (command == 'A')
            {
                set_first_part_of_the_command(char_number, len, commands);
                if (char_number[0] >= '0' && char_number[0] <= '9')
                {
                    
                    number = atoi(char_number);
                    
                    if (commands.Get_data_from_head().my_string[len + 3] == '?')
                    {
                        command_number_S_or_A_question_mark(roots, how_many_atributes_in_particular_root, number, command);
                    }
                    else
                    {
                        command_number_A_atribute(len, commands, roots, number, section);
                    }
                }
                else
                {
                    command_attribute_A_question_mark(len, roots, commands, number_of_nodes);
                }
            }
            else if (command == 'E')
            {
                command_selector_E_attribute(char_number, len, commands, roots, number_of_nodes);
            }
            else if (command == 'D')
            {

                set_first_part_of_the_command(char_number, len, commands);
               /* if (len == 1)
                {
                   char tmp;
                   tmp = char_number[0];
                   number = tmp - '0';
                   number = number - 1;
                }
                else
                {*/
                    
                    number = atoi(char_number) - 1;
              //  }
                
                
                
                if (commands.Get_data_from_head().my_string[len + 3] == '*')
                {

                    roots.Delete(number);
                    number_of_nodes--;
                    cout << number + 1 << ",D,* == deleted" << endl;
                    how_many_atributes_in_particular_root.remove(number);
                    how_many_selectors_in_particular_root.remove(number);
                }
                else
                {
                    short lenght = len + 3;
                    while (commands.Get_data_from_head().my_string[lenght] != 0)
                    {
                        lenght++;
                    }
                    char* char_nbr = new char[lenght - len + 3];
                    for (int i = 0; i < lenght - len + 3; i++)
                    {
                        char_nbr[i] = commands.Get_data_from_head().my_string[len + 3 + i];
                    }
                    My_own_string tmp = char_nbr;
                    short index_to_cancel;
                    if (roots.Get(number) != nullptr)
                    {
                        index_to_cancel = roots.Get(number)->atrybuties.find_index(tmp);
                        roots.Get(number)->atrybuties.remove_by_index(index_to_cancel);
                        roots.Get(number)->values.remove_by_index(index_to_cancel);
                        how_many_atributes_in_particular_root.decreament(number);

                    }
                    if (roots.Get(number)->atrybuties.IsEmpty() == 1)
                    {
                        roots.Delete(number);
                        number_of_nodes--;
                        how_many_atributes_in_particular_root.remove(number);
                        how_many_selectors_in_particular_root.remove(number);
                    }
                    cout << number + 1 << ",D," << tmp << " == deleted" << endl;
                }

            }



        }

        commands.go_to_the_next_element();
    }


    commands.clear_list();
}



bool add_command(char* word)
{
    int key = 0;
    int len = 0;
    while (key != '\n')  //to jeszcze do ustalenia co najelpsze
    {
        if (key == EOF)
        {
            return false;
        }
        key = getchar();
        word[len] = key;
        if (word[len] == '\n')
        {
            word[len] = '\0';
        }
        else
        {
            len++;
        }
    }
    len++;
    word[len - 1] = 0;
    return true;
}
bool read_CMD(short& flags, bools_using_in_programm& bools, Simple_list& add_commands)
{
    bool read = true;
    char word[200];
    while (1 > 0)
    {
        My_own_string string;
        read = add_command(word);
        if (read == false)
        {
            return false;
        }
        string = word;


        if (strcmp(string.my_string, "****") == 0)
        {
            bools.commands = false;
            bools.read_CSS_file = true;
            return true;
        }
        else if (strcmp(string.my_string, "") == 0)
        {
        }
        else
        {
            add_commands.adding_in_simpler_list(string);
        }
    }
    return true;

}


int main() {
    short flags = 0; // 0 - add selector, 1 - add atribute, 2 - add value of atribute,3 -add node, 4 - add command
    short number_of_nodes = 0;
    bools_using_in_programm bools;
    bools.input_mode = true;
    bools.commands = false;
    bools.read_CSS_file = true;
    bools.add_atributes = true;
    bool input_mode = true;
    list_of_int how_many_selectors_in_particular_root;
    list_of_int how_many_atributes_in_particular_root;
    DoubleList<Section> roots;
    Section selec_or_att_or_val;
    Simple_list commands;
    while (input_mode)
    {
        if (bools.read_CSS_file == true)
        {
            input_mode = read_CSS(flags, roots, bools, number_of_nodes, how_many_selectors_in_particular_root, how_many_atributes_in_particular_root);
        }
        else if (bools.commands == true)
        {
            input_mode = read_CMD(flags, bools, commands);
        }
        exec_commands(commands, number_of_nodes, roots, how_many_selectors_in_particular_root, selec_or_att_or_val, how_many_atributes_in_particular_root);
    }

    //My_own_string x;
    //cin >> x;
    //cin >> y;
    //cin >> z;

    //commands.adding_in_simpler_list(x);
    //commands.adding_in_simpler_list(y);
    //commands.adding_in_simpler_list(z);

    how_many_atributes_in_particular_root.clear_list();
    how_many_selectors_in_particular_root.clear_list();
    roots.clear_list();
    commands.clear_list();



    return 0;
}