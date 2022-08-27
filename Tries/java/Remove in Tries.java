/*
Implement the function SearchWord for the Trie class.
For a Trie, write the function for searching a word. Return true if the word is found successfully, otherwise return false.

Note : main function is given for your reference which we are using internally to test the code.
*/

class TrieNode{

    char data;
    boolean isTerminating;
    TrieNode children[];
    int childCount;

    public TrieNode(char data) {
        this.data = data;
        isTerminating = false;
        children = new TrieNode[26];
        childCount = 0;
    }
}

public class Trie {

    private TrieNode root;
    public int count;
    public Trie() {
        root = new TrieNode('\0');
    }

   public void remove(TrieNode root, String word){
        if(word.length() == 0){
            root.isTerminating = false;
            return;
        }
        
        int childIndex = word.charAt(0) - 'a';
        TrieNode child = root.children[childIndex];
        if(child != null){
            remove(child, word.substring(1));
            if(child.isTerminating == false){
                for(int i=0; i<child.children.length; i++){
                    if(child.children[i] != null){
                        return;
                    }
                }
                root.children[childIndex] = null;
            }
        }
        else return;
    }

    public void remove(String word){
        remove(root, word);
    }

    public boolean search(TrieNode root, String word){
        if(root != null){
            if(word.length() == 0) return root.isTerminating;
            else{
                TrieNode child = root.children[word.charAt(0) - 'a'];
                return search(child, word.substring(1));
            }
        }else return false;
    }

    public boolean search(String word){
        return search(root, word);       
    }

    private void add(TrieNode root, String word){
        if(word.length() == 0){
            root.isTerminating = true;
            return;
        }		
        int childIndex = word.charAt(0) - 'a';
        TrieNode child = root.children[childIndex];
        if(child == null){
            child = new TrieNode(word.charAt(0));
            root.children[childIndex] = child;
            root.childCount++;
        }
        add(child, word.substring(1));
    }

    public void add(String word){
        add(root, word);
    }

}