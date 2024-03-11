#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool solution(string str) { // type 특성 상 재귀로 str 잘라서 넘기기 못하겟누 -> strcpy로 복사해서 변형 ㄱㄴ
    bool answer = true;
    vector<char> check_racket;

    for(int i=0; i<str.size(); i++){
        if(str[i]=='(') check_racket.push_back(str[i]);
        else{ 
            if(!check_racket.empty()) check_racket.pop_back();
            else return false;
        }
    }
    if(!check_racket.empty()) answer = false;
    else answer = true;

    return answer;
}
// ㅎㅎ 벡터 삭제할 필요 없이, 그저 n 변수로 카운트 하는 방법도 있었음!

int main(){
    cout<<solution("(())()")<<endl;
    cout<<solution("(())")<<endl;
    cout<<solution("())())")<<endl;

    return 0;
}