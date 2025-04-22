#include <iostream>
#include <string>
#include <set>

enum class command {
    INSERT, DELETE, EXISTS, NEXT, PREV, INVALID
};

command get_cmd(const std::string &str) {
    if (str == "insert") {
        return command::INSERT;
    } else if (str == "delete") {
        return command::DELETE;
    } else if (str == "exists") {
        return command::EXISTS;
    } else if (str == "next") {
        return command::NEXT;
    } else if (str == "prev") {
        return command::PREV;
    }
    return command::INVALID;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::set<int> bst;
    std::string str;
    int x;
    
    while (std::cin >> str >> x) {
        command cmd = get_cmd(str);

        switch (cmd) {
        case command::INSERT:
            bst.insert(x);
            break;
        
        case command::DELETE:
            bst.erase(x);
            break;

        case command::EXISTS:
            std::cout << (bst.find(x) != bst.end() ? "true" : "false") << std::endl;
            break;

        case command::NEXT: {
            auto it = bst.upper_bound(x);
            std::cout << (it == bst.end() ? "none" : std::to_string(*it)) << std::endl;
            break;
        }

        case command::PREV: {
            auto it = bst.lower_bound(x);
            std::cout << (it == bst.begin() ? "none" : std::to_string(*--it)) << std::endl;
            break;
        }

        default:
            break;
        }
    }
}
