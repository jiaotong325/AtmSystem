//
// Created by lushe on 2022/12/8.
//

#ifndef ATMSYSTEM_HEAD_H
#define ATMSYSTEM_HEAD_H
#include <string>
#include <vector>
using std::string;
using std::vector;


class Account {
private:
    string username;//用户名
    int id;//账号
    int password;//密码
    double money;//余额

public:
    Account():money(0){};
    Account(string username,int id,int password,double money)
            :username(username),id(id),password(password),money(money){};

    ~Account(){};
    string getUsername() const;
    void setUsername(string username);
    int getId() const;
    void setId(int id);
    int getPassword() const;
    void setPassword(int password);
    double getMoney() const;
    void setMoney(double money);

    void showMenu();//显示菜单
    void showAccount();//显示账户信息
    void depositMoney();//存款
    void drawMoney();//取款

    void transferMoney();//转账
    void updatePassword();//修改密码
    void remove();//注销账户




};



class bank_Database {
private:
    vector<Account> account;//账户信息
    int account_num;//账户数量


public:
    bank_Database():account(),account_num(0){};
    ~bank_Database(){};

    void showMain();

    int find_Accplace(int id);//通过id查找账户位置
    Account& find_account(int id);//通过id查找账户
    void save(int index);//将第index个账户的信息更新到数据库中
    void login();
    void Register();//开户



    void showinfo(int index);//打印第index个账户的信息

};







#endif //ATMSYSTEM_HEAD_H
