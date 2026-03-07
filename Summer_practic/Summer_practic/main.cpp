// istream_iterator_char_type.cpp
// compile with: /EHsc
#include <iterator>
#include <vector>
#include <iostream>

int main()
{
    using namespace std;

    typedef istream_iterator<int>::char_type CHT1;
    typedef istream_iterator<int>::traits_type CHTR1;

    // Standard iterator interface for reading
    // elements from the input stream:
    cout << "Enter integers separated by spaces & then\n"
        << " any character ( try example: '2 4 f' ): ";

    // istream_iterator for reading int stream
    istream_iterator<int, CHT1, CHTR1> intRead(cin);

    // End-of-stream iterator
    istream_iterator<int, CHT1, CHTR1> EOFintRead;

    while (intRead != EOFintRead)
    {
        cout << "Reading:  " << *intRead << endl;
        ++intRead;
    }
    cout << endl;
}