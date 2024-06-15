class Twitter {
    std::unordered_map<int, std::unordered_set<int>> mAccounts;
    std::vector<std::pair<int, int>> mTwitterFeed;
public:
    Twitter() 
    {
    }

    void postTweet(int userId, int tweetId) 
    {
        mTwitterFeed.push_back( { userId, tweetId } );
    }
    
    vector<int> getNewsFeed(int userId) 
    {
        std::vector<int> tweets;
        for ( int tweet_ind = mTwitterFeed.size() - 1; tweet_ind >= 0 && tweets.size() < 10; tweet_ind-- )
        {
            if ( mAccounts[ userId ].count( mTwitterFeed[ tweet_ind ].first ) || userId == mTwitterFeed[ tweet_ind ].first )
            {
                tweets.push_back( mTwitterFeed[ tweet_ind ].second );
            }
        }
        return tweets;
    }
    
    void follow( int followerId, int followeeId ) 
    {
        mAccounts[ followerId ].insert( followeeId );
    }
    
    void unfollow(int followerId, int followeeId) 
    {
        mAccounts[ followerId ].erase( followeeId );
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */