class Solution {
public:
    bool isValid(string word) {
        int n = word.size();
         vector<char>vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
         
         bool sizeFlag = false;
         bool digitsLetter = true;
         bool vowel = false;
         bool consonant = false;

         if( word.size() >= 3){
            sizeFlag = true;
         }

         for(auto it : word){
            if(find(vowels.begin(), vowels.end(), it) != vowels.end()){
                vowel = true;
                break;
            }
         }

         for(auto it : word){
            if( ( (it >= 'A' && it <= 'Z') || (it >= 'a' && it <= 'z')) && find(vowels.begin(), vowels.end(), it) == vowels.end()){
                    consonant = true;
                    break;
            }
         }

         for(auto it : word){
            if(it == '@' || it == '#' || it == '$' ){
                digitsLetter = false;
                break;
            }
         }

         if(sizeFlag && digitsLetter && consonant && vowel){
            return true;
         }


      return false;
    }
};