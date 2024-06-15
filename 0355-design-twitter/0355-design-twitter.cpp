class Account {
public:
    Account() = delete;
    Account( int id ) :  mUserId( id ) {}
    int mUserId{0};
    std::set<int> mFollowing;
};

class Twitter {
    std::unordered_map<int, Account*> mAccounts;
    std::vector<std::pair<int, int>> mTwitterFeed;
public:
    Twitter() 
    {
        for ( int i = 0; i < 500; i++ )
        {
            mAccounts[ i ] = new Account( i );
            mAccounts[ i ]->mFollowing.insert( i );
        }
    }

    ~Twitter()
    {
        for ( auto & account : mAccounts )
        {
            delete account.second;
        }
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
            if ( mAccounts[ userId ]->mFollowing.count( mTwitterFeed[ tweet_ind ].first ) )
            {
                tweets.push_back( mTwitterFeed[ tweet_ind ].second );
            }
        }
        return tweets;
    }
    
    void follow( int followerId, int followeeId ) 
    {
        mAccounts[ followerId ]->mFollowing.insert( followeeId );
    }
    
    void unfollow(int followerId, int followeeId) 
    {
        mAccounts[ followerId ]->mFollowing.erase( followeeId );
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