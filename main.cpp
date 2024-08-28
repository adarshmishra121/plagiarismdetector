#include <bits/stdc++.h>

using namespace std;

double plagiarismChecker ( const set<string> &set1, const set<string> &set2 ) {

    if ( set1.empty() || set2.empty() )
            return 0.0;

    int union_len = 0;
    int intersection_len = 0;
    auto itr1 = set1.begin();
    auto itr2 = set2.begin();

    while ( itr1 != set1.end() && itr2 != set2.end() ) {

        if ( *itr1 < *itr2 ) {
            itr1++;
        }
        else if ( *itr1 > *itr2 ) {
            itr2++;
        }
        else {
            itr1++;
            itr2++;
            intersection_len++;
        }
        union_len++;
    }

    union_len += distance ( itr1, set1.end() );
    union_len += distance ( itr2, set2.end() );

    return (double) ( intersection_len ) / union_len;


}

int main()
{

    fstream file1, file2;
    string filename;
    vector<string> text1, text2;
    string word;
    set<string> set1, set2;

    filename = "text1.txt";             // filename of the file

    file1.open( filename.c_str() );        // opening file

    while ( file1 >> word ){         // extracting words from the file

        string temp;

        for ( auto ch : word ) {
            if ( isalpha ( ch ) ) temp.push_back( tolower ( ch ) );  // Removing non-alphabetic character from text and pushing each word to vector of strings
        }

        if ( temp.size() )
            text1.push_back( temp );

    }


    filename = "text2.txt";             // filename of the file

    file2.open( filename.c_str() );        // opening file

    while ( file2 >> word ){         // extracting words from the file

        string temp;

        for ( auto ch : word ) {
            if ( isalpha ( ch ) ) temp.push_back( tolower ( ch ) );  // Removing non-alphabetic character from text and pushing each word to vector of strings
        }
        if ( temp.size() )
            text2.push_back( temp );
    }


    for ( int i = 0; i < text1.size() - 2; i++ ) {
        set1.insert( text1[i] + text1[i+1] + text1[i+2] );           // Concatenating 3 continuous words and pushing it to set
    }

    for ( int i = 0; i < text2.size() - 2; i++ ) {                   // Concatenating 3 continuous words and pushing it to set
        set2.insert( text2[i] + text2[i+1] + text2[i+2] );
    }

    double jaccardSimilarity = plagiarismChecker ( set1, set2 );

    int percent = 100 * jaccardSimilarity;

    cout << endl << endl <<endl ;
    cout << "        Your Document is " << percent << "% Plagiarized " ;
    cout << endl << endl <<endl ;

    return 0;
}
