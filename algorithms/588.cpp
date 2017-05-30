#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;

class FileSystem {
private:
    struct File {
        bool isFile;
        unordered_map<string, File *> children;
        string content;
        File() : isFile(false) {};
        ~File() {
            for (auto dir: children)
                delete dir.second;
        }
    };

    File *root;

    vector<string> pathSplit(const string &path) {
        vector<string> result;
        stringstream s(path);
        string item;
        getline(s, item, '/');
        while (getline(s, item, '/'))
            result.push_back(item);
        return result;
    }

    File *goTo(const vector<string> paths) {
        File *dir = root;
        for (int i = 0; i < paths.size(); i++) {
            if (dir->children.find(paths[i]) == dir->children.end())
                dir->children[paths[i]] = new File();
            dir = dir->children[paths[i]];
        }
        return dir;
    }
public:
    FileSystem() {
        root = new File();
    }

    ~FileSystem() {
        delete root;
    }

    vector<string> ls(string path) {
        vector<string> paths = pathSplit(path);
        File *dir = goTo(paths);
        if (dir->isFile)
            return {paths.back()};
        vector<string> result;
        for (auto p: dir->children)
            result.push_back(p.first);
        sort(result.begin(), result.end());
        return result;
    }

    void mkdir(string path) {
        vector<string> paths = pathSplit(path);
        goTo(paths);
    }

    void addContentToFile(string filePath, string content) {
        vector<string> paths = pathSplit(filePath);
        File *file = goTo(paths);
        file->isFile = true;
        file->content += content;
    }

    string readContentFromFile(string filePath) {
        vector<string> paths = pathSplit(filePath);
        File *file = goTo(paths);
        return file->content;
    }
};

int main() {
    return 0;
}
