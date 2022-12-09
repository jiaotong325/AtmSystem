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
        cout<<"===============�û���������==============="<<endl;
        cout<<"1.��ѯ�˻�"<<endl;
        cout<<"2.���"<<endl;
        cout<<"3.ȡ��"<<endl;
        cout<<"4.ת��"<<endl;
        cout<<"5.�޸�����"<<endl;
        cout<<"6.�˳�"<<endl;
        cout<<"7.ע���˻�"<<endl;
        cout<<"�����������"<<endl;
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
                cout<<"��ӭ�´ι��٣�"<<endl;
                return;
            case 7:
                this->remove();
                return;
            default:
                cout<<"�����������"<<endl;
        }

    }

}

void Account::showAccount(){
    cout<<"===============�˻���Ϣ==============="<<endl;
    cout<<"�û�����"<<this->getUsername()<<endl;
    cout<<"�˺ţ�"<<this->getId()<<endl;
    cout<<"��"<<this->getMoney()<<endl;
    cout<<"======================================"<<endl;
}

void Account::depositMoney(){
    cout<<"===============���==============="<<endl;
    cout<<"���������"<<endl;
    double money;
    cin>>money;
    this->setMoney(this->getMoney()+money);
    cout<<"���ɹ���"<<endl;
    this->showAccount();
}

void Account::drawMoney(){
    cout<<"===============ȡ��==============="<<endl;
    cout<<"������ȡ���"<<endl;
    double money;
    cin>>money;
    if (money>this->getMoney()){
        cout<<"���㣡"<<endl;
        return;
    }
    this->setMoney(this->getMoney()-money);
    cout<<"ȡ��ɹ���"<<endl;
    this->showAccount();
}

//��Ҫ����bank_Database����
/*
void Account::transferMoney(){
    cout<<"===============ת��==============="<<endl;
    cout<<"������Է��˺ţ�"<<endl;
    int id;
    cin>>id;
    //flag=find_Accplace(id);
    if (flag==-1){
        cout<<"�˺Ų����ڣ�"<<endl;
        return;
    }
    cout<<"������ת�˽�"<<endl;
    double money;
    cin>>money;
    if (money>this->getMoney()){
        cout<<"���㣡"<<endl;
        return;
    }
    this->setMoney(this->getMoney()-money);
    account[index].setMoney(account[index].getMoney()+money);
    cout<<"ת�˳ɹ���"<<endl;
    this->showAccount();
}
*/

void Account::updatePassword(){
    cout<<"===============�޸�����==============="<<endl;
    cout<<"�����������룺"<<endl;
    int password;
    cin>>password;
    this->setPassword(password);
    cout<<"�޸ĳɹ���"<<endl;
}

void Account::remove(){
    cout<<"===============ע���˻�==============="<<endl;
    cout<<"���������룺"<<endl;
    int password;
    cin>>password;
    if (password!=this->getPassword()){
        cout<<"�������"<<endl;
        return;
    }
    this->setUsername("");
    this->setId(0);
    this->setPassword(0);
    this->setMoney(0);
    cout<<"ע���ɹ���"<<endl;
}


void bank_Database::showinfo(int index){
    //��ӡ�˻���Ϣ
    cout<<account[index].getUsername()<<endl;
    cout<<account[index].getId()<<endl;
    cout<<account[index].getPassword()<<endl;
    cout<<account[index].getMoney()<<endl;
}



void bank_Database::showMain(){
    cout<<"==================��ӭ������ҳ====================="<<endl;
    while (true){
        cout<<"�������������Ĳ���"<<endl;
        cout<<"1.��¼"<<endl;
        cout<<"2.����"<<endl;
        cout<<"0.�˳�"<<endl;
        cout<<"�����������ˣ�"<<endl;
        //cout<<num<<endl;
        //cout<<accounts[0].getMoney()<<endl;
        //cout<<accounts[1].getMoney();
        char command;
        cin>>command;
        switch (command) {
            case '1'://��¼
                this->login();
                break;
            case '2'://ע��
                this->Register();
                break;
            case '0':
                return;
            default:
                cout<<"��������������";
        }
    }
}


void bank_Database::login(){
    if(account_num==0){//�˻�������
        cout<<"��ǰϵͳ���κ��˻�������Ҫ��ע�ᣡ"<<endl;
        return;
    }
    //���û��������뿨��
    while(true){
        cout<<"���������¼���ţ�"<<endl;
        int cardId;
        cin>>cardId;
        //Ѱ�Ҹÿ��Ŷ�Ӧ���˻�λ��
        int index = this->find_Accplace(cardId);

        //cout<<"����:"<<endl;
        //showinfo(index);

        Account acc;

        if(index!=-1){//�û��������
            while (true){
                //!!!����û���ҵ�ԭ��accָ�����accounts[0]��������accounts[index]
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
                cout<<"�������¼����"<<endl;
                int password;
                cin>>password;
                if(password==acc.getPassword()){//������ȷ
                    cout<<"��¼�ɹ���"<<endl;
                    acc.showMenu();
                    //ͬ������
                    //this->save(index);//�б���������Ҫ����
                    return;
                }
                else{
                    cout<<"���������������������룡"<<endl;
                }
            }
        } else{
            cout<<"�Բ��𣬲����ڸÿ��ŵ��û���"<<endl;
        }
    }

}


void bank_Database::Register() {//��������
    cout<<"===============�û���������=================="<<endl;
    cout<<"�������뿪�����ƣ�"<<endl;
    string name;
    cin>>name;
    int password;
    while (true){
        cout<<"�������뿪�����룺"<<endl;
        cin>>password;
        cout<<"��������ȷ�����룺"<<endl;
        int okPassword;
        cin>>okPassword;

        if(password==okPassword){
            break;
        } else{
            cout<<"�����������һ�£�����������"<<endl;
        }
    }
    //�������һ�����ΰ�λ��
    int cardId = rand()%100000000;

    //�жϸÿ����Ƿ��Ѿ�����
    while (true){
        if(this->find_Accplace(cardId)!=-1){
            cardId = rand()%100000000;
        } else{
            break;
        }
    }
    //�����˻�����
    Account acc(name,cardId,password,0);
    //���˻�������ӵ�����vector��
    this->account.push_back(acc);
    this->account_num++;
    cout<<"�����ɹ���"<<endl;
    cout<<"���Ŀ���Ϊ��"<<cardId<<endl;

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
    //��changed�е�����ͬ�������ݿ���

}
