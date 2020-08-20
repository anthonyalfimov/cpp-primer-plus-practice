//
//  STLVector202.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 20/08/2020.
//  Copyright © 2020 Anthony. All rights reserved.
//

//==================================================================================================
// std::vector iterators, methods, and range-based for() loop
//==================================================================================================

#include <iostream>
#include <string>
#include <vector>

namespace
{
    class BookReview
    {
    public:
        bool fill();
        void show() const;
        
    private:
        std::string mTitle;
        int mRating;
    };
}

void showStlVector202()
{
    std::vector<BookReview> bookReviews;        // create an empty vector
    BookReview reviewInput;
    
    while (reviewInput.fill())
        bookReviews.push_back (reviewInput);
    
    if (bookReviews.size() > 0)
    {
        std::cout << "\nThank you. You entered the following:\nRating\tBook\n";
        
        for (BookReview& review : bookReviews)  // without using the reference, a copy of each element is made
            review.show();
        
        std::vector<BookReview> oldBookReviews (bookReviews);
        
        if (bookReviews.size() > 3)
        {
            bookReviews.erase(bookReviews.begin() + 1, bookReviews.begin() + 3);    // remove 2 items
            
            std::cout << "\nAfter erasure:\nRating\tBook\n";
            
            for (auto& review : bookReviews)         // using auto is shorter; use & to avoid copying
                review.show();
            
            bookReviews.insert(bookReviews.begin(), oldBookReviews.begin() + 1,
                               oldBookReviews.begin() + 2);                         // insert 1 item
            
            std::cout << "\nAfter insertion:\nRating\tBook\n";
            
            for (auto& review : bookReviews)
                review.show();
        }
        
        bookReviews.swap(oldBookReviews);
        
        std::cout << "\nSwapping oldBookReviews with bookReviews:\nRating\tBook\n";
        
        for (auto& review : bookReviews)
            review.show();
    }
    else
        std::cout << "Nothing entered!\n";
    
    std::cout << "\nDone.\n";
}

namespace
{
    bool BookReview::fill()
    {
        std::cout << "Enter book title (\"quit\" to quit): ";
        std::getline (std::cin, mTitle);
        
        if (mTitle == "quit")
            return false;
        
        std::cout << "Enger book rating: ";
        std::cin >> mRating;
        
        if (! std::cin)
            return false;
        
        while (std::cin.get() != '\n')      // clean up the input buffer
            continue;
        
        return true;
    }

    void BookReview::show() const
    {
        std::cout << mRating << "\t\t" << mTitle << "\n";
    }
}
