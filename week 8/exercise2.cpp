#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Facebooker {
private:
    string name;
    vector<Facebooker*> friends;

public:
    Facebooker(const string& name) : name(name) {}

    void addFriend(Facebooker* friendPtr) {
        friends.push_back(friendPtr);
    }

    void printFriends() const {
        cout << "Friends of " << name << ": \n";
        for (vector<Facebooker*>::const_iterator friendPtr = friends.begin(); friendPtr != friends.end(); ++friendPtr) {
            cout << (*friendPtr)->name << "\n";
        }
    }

    void printFriendsOfFriends() const {
        cout << "Friends of friends of " << name << ":\n";
        for (vector<Facebooker*>::const_iterator friendPtr = friends.begin(); friendPtr != friends.end(); ++friendPtr) {
            for (vector<Facebooker*>::const_iterator friendOfFriendPtr = (*friendPtr)->friends.begin(); friendOfFriendPtr != (*friendPtr)->friends.end(); ++friendOfFriendPtr) {
                cout << (*friendOfFriendPtr)->name << "\n";
            }
        }
    }

    void printMutualFriends(const Facebooker* other) const {
        cout << "Mutual friends of " << name << " and " << other->name << ":\n";
        for (vector<Facebooker*>::const_iterator friendPtr = friends.begin(); friendPtr != friends.end(); ++friendPtr) {
            for (vector<Facebooker*>::const_iterator friendOfOtherPtr = other->friends.begin(); friendOfOtherPtr != other->friends.end(); ++friendOfOtherPtr) {
                if ((*friendPtr) == (*friendOfOtherPtr)) {
                    cout << (*friendPtr)->name << "\n";
                }
            }
        }
    }
};

int main() {
    // Create Facebookers
    Facebooker alice("Alice");
    Facebooker bob("Bob");
    Facebooker charlie("Charlie");
    Facebooker dave("Dave");

    // Establish friendships
    alice.addFriend(&bob);
    alice.addFriend(&charlie);
    bob.addFriend(&charlie);
    bob.addFriend(&dave);
    charlie.addFriend(&dave);

    // View friends of a given Facebooker
    cout << endl;
    alice.printFriends();
    cout << endl;

    // View friends of friends of a given Facebooker
    alice.printFriendsOfFriends();
    cout << endl;

    // View mutual friends of two given Facebookers
    alice.printMutualFriends(&bob);
    cout << endl;

    return 0;
}
