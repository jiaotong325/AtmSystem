#include <iostream>
#include "head.h"
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

string Account::getUsername() const {
    return username;
}
void Account::setUsername(string username) {
    this->username = username;
}
int Account::getId() const {
    return id;
}
void Account::setId(int id) {
    this->id = id;
}
int Account::getPassword() const {
    return password;
}
void Account::setPassword(int password) {
    this->password = password;
}
double Account::getMoney() const {
    return money;
}
void Account::setMoney(double money) {
    this->money = money;
}

void Account::showMenu(){
    while (true){
        cout<<"===============用户操作界面==============="<<endl;
        cout<<"1.查询账户"<<endl;
        cout<<"2.存款"<<endl;
        cout<<"3.取款"<<endl;
        cout<<"4.转账"<<endl;
        cout<<"5.修改密码"<<endl;
        cout<<"6.退出"<<endl;
        cout<<"7.注销账户"<<endl;
        cout<<"请您输入命令："<<endl;
        //cout<<accounts[0].getMoney()<<endl;
        int command;
        cin>>command;
        switch (command) {
            case 1:
                this->showAccount();
                break;
            case 2:
                this->depositMoney();
                break;
            case 3:
                this->drawMoney();
                break;
            case 4:
                //this->transferMoney();
                break;
            case 5:
                this->updatePassword();
                break;
            case 6:
                cout<<"欢迎下次光临！"<<endl;
                return;
            case 7:
                this->remove();
                return;
            default:
                cout<<"命令输入错误！"<<endl;
        }

    }

}

void Account::showAccount(){
    cout<<"===============账户信息==============="<<endl;
    cout<<"用户名："<<this->getUsername()<<endl;
    cout<<"账号："<<this->getId()<<endl;
    cout<<"余额："<<this->getMoney()<<endl;
    cout<<"======================================"<<endl;
}

void Account::depositMoney(){
    cout<<"===============存款==============="<<endl;
    cout<<"请输入存款金额："<<endl;
    double money;
    cin>>money;
    this->setMoney(this->getMoney()+money);
    cout<<"存款成功！"<<endl;
    this->showAccount();
}

void Account::drawMoney(){
    cout<<"===============取款==============="<<endl;
    cout<<"请输入取款金额："<<endl;
    double money;
    cin>>money;
    if (money>this->getMoney()){
        cout<<"余额不足！"<<endl;
        return;
    }
    this->setMoney(this->getMoney()-money);
    cout<<"取款成功！"<<endl;
    this->showAccount();
}

//需要传入bank_Database对象
/*
void Account::transferMoney(){
    cout<<"===============转账==============="<<endl;
    cout<<"请输入对方账号："<<endl;
    int id;
    cin>>id;
    //flag=find_Accplace(id);
    if (flag==-1){
        cout<<"账号不存在！"<<endl;
        return;
    }
    cout<<"请输入转账金额："<<endl;
    double money;
    cin>>money;
    if (money>this->getMoney()){
        cout<<"余额不足！"<<endl;
        return;
    }
    this->setMoney(this->getMoney()-money);
    account[index].setMoney(account[index].getMoney()+money);
    cout<<"转账成功！"<<endl;
    this->showAccount();
}
*/

void Account::updatePassword(){
    cout<<"===============修改密码==============="<<endl;
    cout<<"请输入新密码："<<endl;
    int password;
    cin>>password;
    this->setPassword(password);
    cout<<"修改成功！"<<endl;
}

void Account::remove(){
    cout<<"===============注销账户==============="<<endl;
    cout<<"请输入密码："<<endl;
    int password;
    cin>>password;
    if (password!=this->getPassword()){
        cout<<"密码错误！"<<endl;
        return;
    }
    this->setUsername("");
    this->setId(0);
    this->setPassword(0);
    this->setMoney(0);
    cout<<"注销成功！"<<endl;
}


void bank_Database::showinfo(int index){
    //打印账户信息
    cout<<account[index].getUsername()<<endl;
    cout<<account[index].getId()<<endl;
    cout<<account[index].getPassword()<<endl;
    cout<<account[index].getMoney()<<endl;
}



void bank_Database::showMain(){
    cout<<"==================欢迎进入首页====================="<<endl;
    while (true){
        cout<<"请输入你想做的操作"<<endl;
        cout<<"1.登录"<<endl;
        cout<<"2.开户"<<endl;
        cout<<"0.退出"<<endl;
        cout<<"您可以输入了："<<endl;
        //cout<<num<<endl;
        //cout<<accounts[0].getMoney()<<endl;
        //cout<<accounts[1].getMoney();
        char command;
        cin>>command;
        switch (command) {
            case '1'://登录
                this->login();
                break;
            case '2'://注册
                this->Register();
                break;
            case '0':
                return;
            default:
                cout<<"您输入的命令错误！";
        }
    }
}


void bank_Database::login(){
    if(account_num==0){//账户不存在
        cout<<"当前系统无任何账户，您需要先注册！"<<endl;
        return;
    }
    //让用户键盘输入卡号
    while(true){
        cout<<"请您输入登录卡号："<<endl;
        int cardId;
        cin>>cardId;
        //寻找该卡号对应的账户位置
        int index = this->find_Accplace(cardId);

        //cout<<"测试:"<<endl;
        //showinfo(index);

        Account acc;

        if(index!=-1){//用户对象存在
            while (true){
                //!!!这里没有找到原因，acc指向的是accounts[0]，而不是accounts[index]
                acc=account[index];
                //acc=this->find_account(index);?
                cout<<acc.getUsername()<<endl;
                //acc=&accounts[index];
                /*
                for (int i = 0; i < account_num; i++) {
                    if(account[i].getId()==cardId){
                        acc = &account[i];
                        break;
                    }
                }
                 */
                cout<<"请输入登录密码"<<endl;
                int password;
                cin>>password;
                if(password==acc.getPassword()){//密码正确
                    cout<<"登录成功！"<<endl;
                    acc.showMenu();
                    //同步数据
                    //this->save(index);//有别名，不需要更新
                    return;
                }
                else{
                    cout<<"您的密码有误，请重新输入！"<<endl;
                }
            }
        } else{
            cout<<"对不起，不存在该卡号的用户！"<<endl;
        }
    }

}


void bank_Database::Register() {//开户功能
    cout<<"===============用户开户功能=================="<<endl;
    cout<<"请您输入开户名称："<<endl;
    string name;
    cin>>name;
    int password;
    while (true){
        cout<<"请您输入开户密码："<<endl;
        cin>>password;
        cout<<"请您输入确认密码："<<endl;
        int okPassword;
        cin>>okPassword;

        if(password==okPassword){
            break;
        } else{
            cout<<"两次密码必须一致！请重新输入"<<endl;
        }
    }
    //随机生成一个整形八位数
    int cardId = rand()%100000000;

    //判断该卡号是否已经存在
    while (true){
        if(this->find_Accplace(cardId)!=-1){
            cardId = rand()%100000000;
        } else{
            break;
        }
    }
    //创建账户对象
    Account acc(name,cardId,password,0);
    //将账户对象添加到容器vector中
    this->account.push_back(acc);
    this->account_num++;
    cout<<"开户成功！"<<endl;
    cout<<"您的卡号为："<<cardId<<endl;

    //showinfo(account_num-1);
}


int bank_Database::find_Accplace(int id){
    for (int i = 0; i < account_num; ++i) {
        if(account[i].getId()==id){
            return i;
        }
    }
    return -1;
}

Account& bank_Database::find_account(int id){
    for (int i = 0; i < account_num; ++i) {
        if(account[i].getId()==id){
            return account[i];
        }
    }
}


void bank_Database::save(int index){
    //将changed中的数据同步到数据库中

}
