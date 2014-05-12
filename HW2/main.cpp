#include <iostream>
#include <fstream>
#include "hash_table.h"
#include <string>


using namespace std;

template <class T>
void print(vector<T> &v)
{
    for (std::size_t i = 0; i < v.size(); ++i)
        cout << v[i] << endl;
        cout << endl;
}

int main()
{

    ifstream input_dictionary("dictionary.txt");
    if (input_dictionary.fail())
    {
       cout << "error" << endl;
        exit(1);
    }

    ifstream input_word_search("puzzle.txt");
    if (input_word_search.fail())
    {
       cout << "error" << endl;
        exit(2);
    }

    hash_table dictionary;
    string s;
    while(!input_dictionary.eof()){
        getline(input_dictionary,s);
        dictionary.insert(s);
    }

    string word;
    vector<string> puz_table;
    while(!input_word_search.eof())

    {
        getline(input_word_search, word);
        for(size_t i=0; i < word.length(); ++i)

             if(word[i] == ' ')
                 word.erase( remove( word.begin(), word.end(), ' ' ), word.end() );
            transform(word.begin(), word.end(), word.begin(), ::tolower);
        puz_table.push_back(word);
    }


    for (int x = 0; x < puz_table.size(); x++)
    {
        for (int y = 0; y< puz_table[x].size(); y++)
        { //We need Variables that will check, left, right, up, down, diagonally, etc.
          //Must be able to increment variables to advance the crossword puzzle
          //and strings to build the words
          //dig= search for

            value_type hor_for = y;
            value_type hor_back = y;
            value_type vert_for_x = x;
            value_type vert_back_x = x;
            value_type dig_for_x = x;
            value_type dig_for_y = y;
            value_type dig_back_x = x;
            value_type dig_back_y = y;
            value_type dig_back_x_left = x;
            value_type dig_back_y_left = y;
            value_type dig_for_x_left = x;
            value_type dig_for_y_left = y;

          string search_forwards;
          string search_backwards;
          string searching_vert_forwards;
          string searching_vert_backwards;
          string searching_dig_forwards;
          string searching_dig_backwards;
          string searching_dig_forwards_left;
          string searching_dig_backwards_left;

            //Check horizontally
            while (hor_for<= puz_table[x].size()-1)
            {
                search_forwards += (puz_table[x][hor_for]);
                if (dictionary.find(search_forwards) == 1)
                    cout << search_forwards << " at ( << x << "," << y << ) " << "to (" << x << "," <<
                                                                                 hor_for << ")" << endl;
                hor_for++;
            }

            //Go in backwards direction horizontally
            while (hor_back>= 0)
            {
                search_backwards += (puz_table[x][hor_back]);
                if (dictionary.find(search_backwards) == 1)
                    cout << search_backwards << " at (" << x << "," << y << ") " << "to (" << x << "," <<
                                                                        hor_back << ")" << endl;
                hor_back--;
            }

            //Check up
            while(vert_for_x <= puz_table.size()-1)
            {
                searching_vert_forwards += puz_table[vert_for_x][y];
                if (dictionary.find(searching_vert_forwards) == 1)
                    cout << searching_vert_forwards << " at (" << x << "," << y << ") " << "to (" <<
                                                                        vert_for_x << "," << y << ")" << endl;
                vert_for_x++;
            }

            //Check down
            while(ver_back_x >= 0)
            {
                searching_vert_backwards += puz_table[vert_back_x][y];
                if (dictionary.find(searching_vert_backwards) == 1)
                    cout << searching_vert_backwards << " at (" << x << "," << y << ") " << "to (" <<
                                                                        vert_back_x << "," << y << ")" << endl;
                vert_back_x--;
            }

            //Diagonal forwards
            while((dig_for_x <= puz_table.size()-1) && (dig_for_y <= puz_table[x].size()-1) )
            {
                searching_dig_forwards += puz_table[dig_for_x][dig_for_y];
                if (dictionary.find(searching_dig_forwards) == 1)
                    cout << searching_dig_forwards << " at (" << x << "," << y << ") " << "to (" <<
                                                                        dig_for_x << "," << dig_for_y << ")" << endl;
                dig_for_x++;
                dig_for_y++;
            }

            //Diagonal backwards
            while((dig_for_x_left >= 0) && (dig_for_y_left >=0) )
            {
                searching_dig_forwards_left += puz_table[dig_for_x_left][dig_for_y_left];
                if (dictionary.find(searching_dig_forwards_left) == 1)
                    cout << searching_dig_forwards_left << " at (" << x << "," << y << ") " << "to (" <<
                                                                        dig_for_x_left << "," << dig_for_y_left << ")" << endl;
                dig_for_x_left--;
                dig_for_y_left--;
            }

            //diagonal right
            while((dig_back_x >= 0) && (dig_back_y <= puz_table[x].size()-1) )
            {
                searching_dig_backwards += puz_table[dig_back_x][dig_back_y];
                if (dictionary.find(searching_dig_backwards) == 1)
                    cout << searching_dig_backwards << " at (" << x << "," << y << ") " << "to (" <<
                                                                        dig_back_x << "," << dig_back_y << ")" << endl;
                dig_back_x--;
                dig_back_y++;
            }

            //Diagonal left
            while((dig_back_x_left <= puz_table.size()-1) && (dig_back_y_left >=0) )
            {
                searching_dig_backwards_left += puz_table[dig_back_x_left][dig_back_y_left];
                if (dictionary.find(searching_dig_backwards_left) == 1)
                    cout << searching_dig_backwards_left << " at (" << x << "," << y << ") " << "to (" <<
                                                                        dig_back_x_left << "," << dig_back_y_left << ")" << endl;
                dig_back_x_left++;
                dig_back_y_left--;
            }

        }
    }

    return 0;

}
