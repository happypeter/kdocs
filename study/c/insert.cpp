insert

Syntax:

    #include <vector>
    iterator insert( iterator loc, const TYPE& val );
    void insert( iterator loc, size_type num, const TYPE& val );
    void insert( iterator loc, input_iterator start, input_iterator end );

The insert method either:

    *
      inserts val before loc, returning an iterator to the element inserted,
    *
      inserts num copies of val before loc, or
    *
      inserts the elements from start to end before loc.

Note that inserting elements into a vector can be relatively time-intensive, since the underlying data structure for a vector is an array. In order to insert data into an array, you might need to displace a lot of the elements of that array, and this can take linear time. If you are planning on doing a lot of insertions into your vector and you care about speed, you might be better off using a container that has a linked list as its underlying data structure (such as a list or a deque).

For example, the following code uses the insert() function to splice four copies of the character 'C' into a vector of characters:

   // Create a vector, load it with the first 10 characters of the alphabet
   vector<char> alphaVector;
   for( int i=0; i < 10; i++ ) {
     alphaVector.push_back( i + 'A' );
   }
 
   // Insert four C's into the vector
   vector<char>::iterator theIterator = alphaVector.begin();
   alphaVector.insert( theIterator, 4, 'C' );
 
   // Display the vector
   for( theIterator = alphaVector.begin(); theIterator != alphaVector.end(); ++theIterator )    {
     cout << *theIterator;
   }

This code would display:

   CCCCABCDEFGHIJ

Here is another example of the insert method. In this code, insert is used to append the contents of one vector into the end of another:

    vector<int> v1;
    v1.push_back( 0 );
    v1.push_back( 1 );
    v1.push_back( 2 );
    v1.push_back( 3 );
 
    vector<int> v2;
    v2.push_back( 5 );
    v2.push_back( 6 );
    v2.push_back( 7 );
    v2.push_back( 8 );
 
    cout << "Before, v2 is: ";
    for( int i = 0; i < v2.size(); i++ ) {
      cout << v2[i] << " ";
    }
    cout << endl;
 
    v2.insert( v2.end(), v1.begin(), v1.end() );
 
    cout << "After, v2 is: ";
    for( int i = 0; i < v2.size(); i++ ) {
      cout << v2[i] << " ";
    }
    cout << endl;

When run, this code displays:

    Before, v2 is: 5 6 7 8
    After, v2 is: 5 6 7 8 0 1 2 3

Related Topics: assign, erase, push_back

