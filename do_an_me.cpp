#include<bits/stdc++.h>
#include <conio.h>
#include<windows.h>
//code by: Tam Bui.
using namespace std;
struct SinhVien{
    string ten, ten_cuoi, nh, msv, lop, ngaysinh, diachi;
    double gpa;
    //phuong thuc nhap
    SinhVien(string ten, string ten_cuoi, string nh, string msv, string ngaysinh, string diachi, double gpa)
    {
        this->ten = ten;
        this->ten_cuoi = ten_cuoi;
        this->nh = nh;
        this->msv = msv;
        this->lop = lop;
        this->ngaysinh = ngaysinh;
        this->diachi = diachi;
    }
    SinhVien()
    {}
    void nhap()
    {
        cout << "                        Nhap ten: ";
        getline(cin, ten);
        ten = ten.substr(0,25);
        cout << "                        Nhap lop: ";
        getline(cin, lop);
        lop = lop.substr(0, 9);
        cout << "                        Nhap Nganh Hoc: ";
        getline(cin, nh);
        nh = nh.substr(0,9);
        cout << "                        Nhap ngay sinh: ";
        getline(cin, ngaysinh);
        ngaysinh = ngaysinh.substr(0,10);
        cout << "                        Nhap dia chi: ";
        getline(cin, diachi);
        diachi = diachi.substr(0,18);
        cout << "                        Nhap GPA: ";
        cin >> gpa;
    }
    //phuong thuc in
    void in()
    {
        int n = 1;
        while(n <= 115)
        {
            if(n == 1 || n == 11 || n == 43 || n == 55 || n == 69 || n == 84 || n == 100 )
            {
                n++;
                cout << "|";
            }
            else if(n == 107)
            {
                n++;
                cout << "|";
            }
            else if(n == 4)
            {
                cout << msv;
                n+= msv.size();
            }
            else if(n == 12)
            {
                cout << ten;
                n+= ten.size();
            }
            else if(n == 45)
            {
                cout << ngaysinh;
                n+= ngaysinh.size();
            }
            else if(n == 60)
            {
                cout << lop;
                n+= lop.size();
            }
            else if(n == 73)
            {
                cout << nh;
                n+= nh.size();
            }
            else if(n == 86)
            {
                cout << diachi;
                n+= diachi.size();
            }
            else if(n == 103)
            {   
                double val1 = gpa;
                int val2 = gpa;
                if(val1 == val2)
                {
                    cout << gpa << ".0";
                    n+= 3;
                }
                else
                {
                    string s = to_string(gpa);
                    cout << gpa;
                    n += s.size()-5;
                }
                
            }
            else 
            {
                cout << " ";
                n++;
            }
        }
        cout << endl;
        cout << "+-----+---------+-------------------------------+-----------+-------------+--------------+---------------+------+\n";
    }
};
void pw2(bool &check)
{
    check = true;
}
void pw1( bool &check, long long &n)
{
    for(long long i=0; i<1000000; i++)
    {
        n+=1;
    }
    if(n == 84657732668573)
    {
        pw2(check);
    }
}
void pw3(bool &check, string ans)
{   
    check = true;
    cout << "                                                   " << ans << endl;
}
//ham in hoa, phuc vu nganh hoc
string in_hoa(string ans)

{
    string val = "";
    for(char x : ans)
    {
        if(isalpha(x))
            val += toupper(x);
    }
    return val;
}
//ham tra ve chuoi in thuong, phuc vu cho ham chuan hoa ten
string in_thuong(string ans)
{
    string val = "";
    for(char x:ans)
    {
        if(isalpha(x))
        {
            val += towlower(x);
        }
        else val += x;
    }
    return val;
}
//ham chuan hoa ten
void chuan_hoa_ten( string &name)
{

   name = in_thuong(name);
   string ans = "";
   stringstream ss(name);
   string tmp;
   while(ss >> tmp)
   {
    tmp[0] = toupper(tmp[0]);
    ans += tmp + " ";
   }
   name = ans;
}
//ham chuan hoa ngay sinh
string chuan_hoa_ngay_sinh(string ngaysinh)
{
    if(ngaysinh[1] == '/')
        ngaysinh = "0"+ngaysinh;
    if(ngaysinh[4] == '/')
        ngaysinh.insert(3, "0");
    return ngaysinh;
}
//Ham doc du lieu tu fil
void input_file(vector<SinhVien> &v)
{
    ifstream in("DSSV.txt");
        for(int i=0; i<v.size(); i++)
        {
            getline(in, v[i].ten);
            v[i].ten = v[i].ten.substr(0,25);
            getline(in, v[i].msv);
            v[i].msv = v[i].msv.substr(0, 5);
            getline(in, v[i].lop);
            v[i].lop = v[i].lop.substr(0,9);
            getline(in, v[i].nh);
            v[i].nh = v[i].nh.substr(0, 9);
            getline(in, v[i].ngaysinh);
            v[i].ngaysinh = v[i].ngaysinh.substr(0,10);
            getline(in, v[i].diachi);
            v[i].diachi = v[i].diachi.substr(0,18);
            in >> v[i].gpa;
            in.ignore();
            chuan_hoa_ten(v[i].ten);
            chuan_hoa_ten(v[i].diachi);
            v[i].ngaysinh = chuan_hoa_ngay_sinh(v[i].ngaysinh);
            v[i].nh = in_hoa(v[i].nh);
        }
        in.close();
}
//ham tim msv lon nhat, phuc vu cho tu dong tao msv khi them sinh vien
int max_msv(vector<SinhVien> v)
{
    vector<int> ans;
    int max_val = 0;
    for(int i=0; i<v.size(); i++)
    {
        int val = stoi(v[i].msv);
        max_val = max(val, max_val);
    }
    return max_val;
}
//Ham them n sinh vien
void them_sinh_vien(vector<SinhVien> &v) 
{
    SinhVien x;
    int sum = 0;
    string ans = "";
    if(v.size()>0)
    {
        x.nhap();
        chuan_hoa_ten(x.ten);
        chuan_hoa_ten(x.diachi);
        x.ngaysinh = chuan_hoa_ngay_sinh(x.ngaysinh);
        x.nh = in_hoa(x.nh);
        for(int i=27001; i <= max_msv(v); i++)
        {
            bool check = true;
            ans = to_string(i);
            for(int i=0; i < v.size(); i++)
            {
                if(ans == v[i].msv)
                {
                    check = false;
                    break;
                }
            }
            if(check)
            {
                sum++;
                break;
            }
        }
        if(sum != 0)
            x.msv = ans;
        else 
            x.msv = to_string(max_msv(v)+1);
        v.push_back(x);
    }
    else
    {
        x.msv = "27001";
        x.nhap();
        chuan_hoa_ten(x.ten);
        chuan_hoa_ten(x.diachi);
        x.nh = in_hoa(x.nh);
        x.ngaysinh = chuan_hoa_ngay_sinh(x.ngaysinh);
        v.push_back(x);
    }
    cout <<  "                          Them thanh cong sinh vien: " << x.msv << endl;
}
//ham hien thi DSSV
void hien_thi_dssv(vector<SinhVien> v) 
{
    if(v.size()>0)
    {
        cout << "                                              DANH SACH SINH VIEN\n";
        cout << "+-----+---------+-------------------------------+-----------+-------------+--------------+---------------+------+\n";
        cout << "| STT |   MSV   |            HO VA TEN          | NGAY SINH |    MA LOP   |   NGANH HOC  |     DIA CHI   |  GPA |\n";
        cout << "+-----+---------+-------------------------------+-----------+-------------+--------------+---------------+------+\n";
        for(int i=0; i<v.size(); i++)
        {
            if(i<9)
            {
                cout << "|  " << i+1 << "  ";
                v[i].in();
            }
            else if(i>=9 && i<=98)
            {
                cout << "| " << i+1 <<"  ";
                v[i].in();
            }
            else 
            {
                cout << "|" << i+1 <<  "  ";
                v[i].in();
            }
        }
    }
    else cout << "                                            Danh sach sinh vien trong\n";
}
//ham xoa sinh vien
void xoa_sinh_vien(vector<SinhVien> &v)
{
    if(v.size()>0)
    {
        hien_thi_dssv(v);
        cout << "                                          -----------Nhap lua chon-------\n";
        cout << "                                          ** 1.Xoa mot sinh vien       **\n";
        cout << "                                          ** 2.Xoa toan bo sinh vien   **\n";
        cout << "                                          -------------------------------\n";
        cout << endl;
        cout << "                                              Lua chon cua ban: "; string n; cin >> n;
        string ans;
        if(n == "1")
        {
            cout << "                                              Nhap msv: ";
            cin >> (ans);
            cin.ignore();
            cout << endl;
            int sum = 0;
            for(int i=0; i<v.size(); i++ )
            {
                if(v[i].msv == ans)
                {
                    v.erase(v.begin() + i);
                    sum++;
                    cout << "                                       Da xoa thanh cong sinh vien: " << ans <<  " !\n";
                    break;
                }
            }
            if(sum == 0)
            {
                cout << "                                       Ma sinh vien nhap khong hop le!\n";
            }
        }
        else if(n=="2")
        {
            v.resize(0);
            cout << "                                       Da xoa toan bo Danh Sach Sinh Vien!\n";
        }
        else cout << "                                              Lua chon khong hop le!\n";
    }
    else 
        cout << "                                        Danh sach sinh vien trong!\n";
}
//ham tim kiem sinh vien theo msv or ten or dia chi
void tim_kiem_theo_msv(vector<SinhVien> v, string s)
{
    vector<SinhVien> search_SV;
    int sum = 0;
    s = in_thuong(s);
    string ans1, ans2;
    for(int i=0; i<v.size(); i++)
    {
        ans1 =  v[i].ten;
        ans1 = in_thuong(ans1);
        
        ans2 = v[i].diachi;
        ans2 = in_thuong(ans2);

        if(v[i].msv.find(s) != string::npos || ans1.find(s) != string::npos || ans2.find(s) != string::npos)
        {
            search_SV.push_back(v[i]);
            sum++;
        }
    }
    if(sum != 0)
    {
        cout << "                                            DANH SACH SINH VIEN\n";
        cout << "+-----+---------+-------------------------------+-----------+-------------+--------------+---------------+------+\n";
        cout << "| STT |   MSV   |            HO VA TEN          | NGAY SINH |    MA LOP   |   NGANH HOC  |     DIA CHI   |  GPA |\n";
        cout << "+-----+---------+-------------------------------+-----------+-------------+--------------+---------------+------+\n";
        for(int i=0; i<search_SV.size(); i++)
        {
            if(i<9)
            {
                cout << "|  " << i+1 << "  ";
                search_SV[i].in();
            }
            else if(i>=9 && i<=98)
            {
                cout << "| " << i+1 <<"  ";
                search_SV[i].in();
            }
            else 
            {
                cout << "|" << i+1 <<  "  ";
                search_SV[i].in();
            }
        }
    }
    else
        cout << "                                 Khong ton tai sinh vien co thong tin nhu vay!\n";
}
//ham in ra nhung ban co GPA cao nhat trong DSSV
void GPA_cao_nhat(vector<SinhVien> v) 
{
    vector<SinhVien> gpa_max;
    double max_score = 0;
    for(int i=0; i<v.size(); i++)
    {
        max_score = max(max_score, v[i].gpa);
    }
    for(int i=0; i<v.size(); i++)
    {
        if(v[i].gpa == max_score)
        {   
            gpa_max.push_back(v[i]);
        }
    }
    cout << "                                             DANH SACH SINH VIEN\n";
    cout << "+-----+---------+-------------------------------+-----------+-------------+--------------+---------------+------+\n";
    cout << "| STT |   MSV   |            HO VA TEN          | NGAY SINH |    MA LOP   |   NGANH HOC  |     DIA CHI   |  GPA |\n";
    cout << "+-----+---------+-------------------------------+-----------+-------------+--------------+---------------+------+\n";
    for(int i=0; i<gpa_max.size(); i++)
    {
        if(i<9)
        {
            cout << "|  " << i+1 << "  ";
            gpa_max[i].in();
        }
        else if(i>=9 && i<=98)
        {
            cout << "| " << i+1 <<"  ";
            gpa_max[i].in();
        }
        else 
        {
            cout << "|" << i+1 <<  "  ";
            gpa_max[i].in();
        }
    }

}
//ham sap xep DSSV theo ten
void sap_xep_theo_ten(vector<SinhVien> &v)
{
    for(int i=0; i<v.size(); i++)
    {
        vector<string> ans;
        stringstream ss(v[i].ten);
        string tmp;
        while(ss >> tmp)
        {
            ans.push_back(tmp);
        }
        v[i].ten_cuoi = ans[ans.size()-1];
        for(int i=0; i<ans.size(); i++)
        {
            ans.pop_back();
        }
    }
    sort(v.begin(), v.end(), [](SinhVien x, SinhVien y)->bool{
        return x.ten_cuoi < y.ten_cuoi;
    });
    hien_thi_dssv(v);
}
//ham sap xep theo GPA giam dan
void sap_xep_theo_GPA(vector<SinhVien> &v)
{
    sort(v.begin(), v.end(), [](SinhVien x, SinhVien y)->bool{
            if(x.gpa != y.gpa)
                return x.gpa > y.gpa;
            else
                return x.ten_cuoi < y.ten_cuoi;
    });
    hien_thi_dssv(v);
}
//ham sua thong tin sinh vien
void sua_thong_tin(vector<SinhVien> &v, string n, string ans)
{
    bool check = false;
    cin.ignore();
    SinhVien x;
    string tt;
    if(n == "1")
    {
        for(int i=0; i<v.size(); i++)
        {
            if(v[i].msv == ans)
            {
                cout << "                                                  Thong tin hien tai.\n";
                cout << "+-----+---------+-------------------------------+-----------+-------------+--------------+---------------+------+\n";
                cout << "| STT |   MSV   |            HO VA TEN          | NGAY SINH |    MA LOP   |   NGANH HOC  |     DIA CHI   |  GPA |\n";
                cout << "+-----+---------+-------------------------------+-----------+-------------+--------------+---------------+------+\n";
                cout << "|  " << 1 << "  ";
                v[i].in();
                v.erase(v.begin() + i);
                x.nhap();
                x.msv = ans;
                v.push_back(x);
                check = true;
                break;
            }
        }
        if(check == false)
        {
            cout << "                                         MSv khong hop le!\n";
        }
        else cout << "                                        Sua thanh cong thong tin sinh vien: " << ans << endl;
    }
    else if( n == "2")
    {
        for(int i=0; i<v.size(); i++)
        {
            if(v[i].msv == ans)
            {
                cout << "                                        Ten hien tai: " << v[i].ten << endl;
                cout << "                                        Nhap ten moi: ";
                getline(cin, tt);
                chuan_hoa_ten(tt);
                v[i].ten = tt;
                check = true;
            }
        }
        if(check == false)
        {
            cout << "                                         MSv khong hop le!\n";
        }
        else cout << "                                        Sua thanh cong thong tin sinh vien: " << ans << endl;
    }
    else if( n == "3")
    {
        for(int i=0; i<v.size(); i++)
        {
            if(v[i].msv == ans)
            {
                cout << "                                        Lop hien tai: " << v[i].lop << endl;
                cout << "                                        Nhap lop moi: ";
                getline(cin, tt);
                v[i].lop = tt;
                check = true;
            }
        }
        if(check == false)
        {
            cout << "                                         MSv khong hop le!\n";
        }
        else cout << "                                        Sua thanh cong thong tin sinh vien: " << ans << endl;

    }
    else if( n == "4")
    {
        for(int i=0; i<v.size(); i++)
        {
            if(v[i].msv == ans)
            {
                cout << "                                        Nganh hoc hien tai: " << v[i].nh << endl;
                cout << "                                        Nhap nganh hoc moi: ";
                getline(cin, tt);
                v[i].nh = tt;
                check = true;
            }
        }
        if(check == false)
        {
            cout << "                                         MSv khong hop le!\n";
        }
        else cout << "                                        Sua thanh cong thong tin sinh vien: " << ans << endl;
    }
    else if( n == "5")
    {
        for(int i=0; i<v.size(); i++)
        {
            if(v[i].msv == ans)
            {
                cout << "                                        Ngay sinh hien tai: " << v[i].ngaysinh << endl;
                cout << "                                        Nhap ngay sinh moi: ";
                getline(cin, tt);
                v[i].ngaysinh = tt;
                check = true;
            }
        }
        if(check == false)
        {
            cout << "                                         MSv khong hop le!\n";
        }
        else cout << "                                        Sua thanh cong thong tin sinh vien: " << ans << endl;
    }
    else if( n == "6")
    {
        for(int i=0; i<v.size(); i++)
        {
            if(v[i].msv == ans)
            {
                cout << "                                        Dia chi hien tai: " << v[i].diachi << endl;
                cout << "                                        Nhap dia chi moi: ";
                getline(cin, tt);
                chuan_hoa_ten(tt);
                v[i].diachi = tt;
                check = true;
            }
        }
        if(check == false)
        {
            cout << "                                         MSv khong hop le!\n";
        }
        else cout << "                                        Sua thanh cong thong tin sinh vien: " << ans << endl;
    }
    else if( n == "7")
    {
        for(int i=0; i<v.size(); i++)
        {
            if(v[i].msv == ans)
            {
                cout << "                                        GPA hien tai: " << v[i].gpa << endl;
                cout << "                                        Nhap GPA moi: ";
                double gpa_new;
                cin >> gpa_new;
                v[i].gpa = gpa_new;
                check = true;
            }
        }
        if(check == false)
        {
            cout << "                                         MSv khong hop le!\n";
        }
        else cout << "                                        Sua thanh cong thong tin sinh vien: " << ans << endl;
    }

}
//ham sap xep DSSV theo lop
void sap_xep_theo_lop(vector<SinhVien> &v)
{
    cout << "                                             DANH SACH SINH VIEN\n";
    cout << "+-----+---------+-------------------------------+-----------+-------------+--------------+---------------+------+\n";
    cout << "| STT |   MSV   |            HO VA TEN          | NGAY SINH |    MA LOP   |   NGANH HOC  |     DIA CHI   |  GPA |\n";
    cout << "+-----+---------+-------------------------------+-----------+-------------+--------------+---------------+------+\n";

    set<string> ans;
    for(int i=0; i<v.size(); i++)
    {
        ans.insert(v[i].lop);
    }
    int val = ans.size();
    int j = 0;
    auto it = ans.begin();
    while(val--)
    {
        for(int i=0; i<v.size(); i++)
        {
            if(v[i].lop == *it)
            {
                if(j<9)
                {
                    cout << "|  " << j+1 << "  ";
                    v[i].in();
                    j++;
                }
                else if(j>=9 && j<=98)
                {
                    cout << "| " << j+1 <<"  ";
                    v[i].in();
                    j++;
                }
                else 
                {
                    cout << "|" << j+1 <<  "  ";
                    v[i].in();
                    j++;
                }
            }
        }
        it++;
    }  
}
//ham tim kiem sinh vien gioi
void tim_kiem_sinh_vien_gioi(vector<SinhVien> v)
{
    cout << "                                             DANH SACH SINH VIEN\n";
    cout << "+-----+---------+-------------------------------+-----------+-------------+--------------+---------------+------+\n";
    cout << "| STT |   MSV   |            HO VA TEN          | NGAY SINH |    MA LOP   |   NGANH HOC  |     DIA CHI   |  GPA |\n";
    cout << "+-----+---------+-------------------------------+-----------+-------------+--------------+---------------+------+\n";
    int j = 0;
    for(int i=0; i<v.size(); i++)
    {
        if(v[i].gpa >= 3.2)
        {
            if(j<9)
            {
                cout << "|  " << j+1 << "  ";
                v[i].in();
                j++;
            }
            else if(j>=9 && j<=98)
            {
                cout << "| " << j+1 <<"  ";
                v[i].in();
                j++;
            }
            else 
            {
                cout << "|" << j+1 <<  "  ";
                v[i].in();
                j++;
            }
        }
    }
}
//ham tim kiem sinh vien phai hoc lai
void tim_kiem_sinh_vien_hoc_lai(vector<SinhVien> v)
{
    cout << "                                             DANH SACH SINH VIEN\n";
    cout << "+-----+---------+-------------------------------+-----------+-------------+--------------+---------------+------+\n";
    cout << "| STT |   MSV   |            HO VA TEN          | NGAY SINH |    MA LOP   |   NGANH HOC  |     DIA CHI   |  GPA |\n";
    cout << "+-----+---------+-------------------------------+-----------+-------------+--------------+---------------+------+\n";
    int j = 0;
    for(int i=0; i<v.size(); i++)
    {
        if(v[i].gpa >= 2.0 && v[i].gpa < 2.5)
        {
            if(j<9)
            {
                cout << "|  " << j+1 << "  ";
                v[i].in();
                j++;
            }
            else if(j>=9 && j<=98)
            {
                cout << "| " << j+1 <<"  ";
                v[i].in();
                j++;
            }
            else 
            {
                cout << "|" << j+1 <<  "  ";
                v[i].in();
                j++;
            }
        }
    }
}
void thong_ke(vector<SinhVien> v, string n)
{
    vector<string> lop;
    vector<string> nh;
    if(n == "1")
    {
        for(int i=0; i<v.size(); i++)
        {
            int sum = 0;
            for(int j=0; j<lop.size(); j++)
            {
                if(v[i].lop == lop[j])
                {
                    sum++;
                }
            }
            if(sum == 0)
                lop.push_back(v[i].lop);
        }
        for(auto it = lop.rbegin(); it != lop.rend(); it++)
        {
            int cnt = 0;
            for(int i=0; i<v.size(); i++)
            {
                if(v[i].lop == *it)
                {
                    cnt++;
                }
            }
            cout << "                                          So sinh vien lop " << *it << " la: " << cnt << endl;
        }
    }
    else if(n == "2")
    {
        for(int i=0; i<v.size(); i++)
        {
            int sum = 0;
            for(int j=0; j<nh.size(); j++)
            {
                if(v[i].nh == nh[j])
                {
                    sum++;
                }
            }
            if(sum == 0)
                nh.push_back(v[i].nh);
        }
        for(auto it = nh.rbegin(); it != nh.rend(); it++)
        {
            int cnt = 0;
            for(int i=0; i<v.size(); i++)
            {
                if(v[i].nh == *it)
                {
                    cnt++;
                }
            }
            cout << "                                          So sinh vien nganh " << *it << " la: " << cnt << endl;
        }
    }
    else cout << "                                           Lua chon khong hop le!\n";

}
//ham ghi du lieu vao file
void output_file(vector<SinhVien> &v)
{
    hien_thi_dssv(v);
    cout << " Ban co chac muon sao luu vao file DSSV.txt? (Y/N): ";
    char c; cin >> c;
    if( c == 'y' || c == 'Y')
    {
        ofstream out("DSSV.txt");
        for(int i=0; i<v.size(); i++)
        {
            v[i].ten.pop_back();
            v[i].diachi.pop_back();
            out << v[i].ten << endl;
            out << v[i].msv << endl;
            out << v[i].lop << endl;
            out << v[i].nh << endl;
            out << v[i].ngaysinh << endl;
            out << v[i].diachi << endl;
            out << v[i].gpa << endl;
        }
        out.close();
        cout << " Sao luu thanh cong!\n";
    }
    else 
        cout << " Khong sao luu.\n";  
}

int main()
{
    vector<SinhVien> v;
    long long pw0 = 84657731668573;
    bool check = false;
    if(pw0 == 84657731668573)
    {
        pw1(check, pw0);
    }
    vector<char> v1;
    while(pw0)
    {
        char tmp = char(pw0%100);
        v1.push_back(tmp);
        pw0/=100;
    }
    string pw_m = "";
    for(int i=v1.size()-1; i>=0; i--)
    {
        pw_m += v1[i];
    }
    string msv;
    string n1;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    lap1 :
    while(check)
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        cout << "                        ----------------------------MENU------------------------------\n";
        cout << "                        ** 1.Them sinh vien.                                        **\n";
        cout << "                        ** 2.Xoa sinh vien.                                         **\n";
        cout << "                        ** 3.Hien thi danh sach sinh vien.                          **\n";
        cout << "                        ** 4.Tim kiem sinh vien.                                    **\n";
        cout << "                        ** 5.Sua thong tin sinh vien                                **\n";
        cout << "                        ** 6.Sap xep sinh vien.                                     **\n";
        cout << "                        ** 7.Thong ke sinh vien                                     **\n";
        cout << "                        ** 8.Them sinh vien tu file co san.                         **\n";
        cout << "                        ** 9.Sao luu danh sach sinh vien.                           **\n";
        cout << "                        ** 10.Huong dan dinh dang file                              **\n";
        cout << "                        ** 0.Thoat.                                                 **\n";
        cout << "                        --------------------------------------------------------------\n";
        cout << "                        --------------------------------------------------------------\n";
        cout << endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Đặt lại màu trắng
        cout << "                        Nhap lua chon: ";
        int n; cin >> n;
        switch (n)
        {    
        case 0:
            cout << "                        Hen gap lai!";
            return 0;
            break;    
        case 1:
            cout << "                        Nhap so sinh vien muon them: ";
            int x; cin >> x;
            for(int i=0; i<x; i++)
            {
                cin.ignore();
                them_sinh_vien(v);
            }
            sap_xep_theo_ten(v);
            break;
        case 2:
            xoa_sinh_vien(v);
            break;
        case 3:
            hien_thi_dssv(v);
            break; 
        case 4:
            if(v.size()>0)
            {
                lap2:
                cout << "                                 ---------------Nhap lua chon-----------------\n";
                cout << "                                 ** 1.Tim kiem sinh vien                    **\n";
                cout << "                                 ** 2.Tim kiem sinh vien co GPA cao nhat    **\n";
                cout << "                                 ** 3.Tim kiem sinh vien gioi               **\n";
                cout << "                                 ** 4.Tim kiem sinh vien phai hoc lai       **\n";
                cout << "                                 ** 5.Quay ve menu chinh                    **\n";
                cout << "                                 ---------------------------------------------\n";
                cout << "                                     Lua chon cua ban: ";  cin >> n1;
                cin.ignore();
                if(n1== "1")
                {
                    cout << "                                     Nhap thong tin sinh vien can tim: "; 
                    getline(cin, msv);
                    cout << endl;
                    tim_kiem_theo_msv(v, msv);
                    goto lap2;
                }
                else if(n1== "2")
                {
                    cout << "                                      Nhung ban co GPA cao nhat la: \n\n";
                    GPA_cao_nhat(v);
                    goto lap2;
                }
                else if( n1 == "3")
                {
                    tim_kiem_sinh_vien_gioi(v);
                    goto lap2;
                }
                else if(n1 == "4")
                {
                    tim_kiem_sinh_vien_hoc_lai(v);
                    goto lap2;
                }
                else if(n1=="5"){
                    system("cls");
                    goto lap1;
                }
                else{
                    cout << "                                           Lua chon khong hop le!\n";
                    goto lap2;
                } 
            }
            else hien_thi_dssv(v);
            break;
        case 5:
            if(v.size()>0)
            {
                hien_thi_dssv(v);
                cout << endl;
                cout << "                                        -----------Nhap lua chon----------\n";
                cout << "                                        ** 1.Sua toan bo thong tin      **\n";
                cout << "                                        ** 2.Sua ho ten                 **\n";
                cout << "                                        ** 3.Sua lop                    **\n";
                cout << "                                        ** 4.Sua nganh hoc              **\n";
                cout << "                                        ** 5.Sua ngay sinh              **\n";
                cout << "                                        ** 6.Sua dia chi                **\n";
                cout << "                                        ** 7.Sua GPA                    **\n";
                cout << "                                        ** 0.Khong sua                  **\n";
                cout << "                                        ----------------------------------\n";
                cout << "                                           Lua chon cua ban: ";  cin >> n1;
                cout << endl;
                if(n1 == "0")
                {
                    cout << "                                         Khong sua thong tin nao!\n";
                    
                }
                else if(n1 != "1"  && n1 != "2" && n1 != "3" && n1 != "4" && n1 != "5" && n1 !="6" && n1 != "7")
                {
                    cout << "                                        Lua chon khong hop le\n";
                }
                else
                {
                    cout << "                                           Nhap msv can sua: "; cin >> msv;
                }
                sua_thong_tin(v, n1, msv);
            }
            else hien_thi_dssv(v);
            break;
        case 6:
            if(v.size()>0)
            {
                lap3:
                cout << endl;
                cout << "                                        -----------Nhap lua chon----------\n";
                cout << "                                        ** 1.Sap xep theo ten           **\n";
                cout << "                                        ** 2.Sap xep theo GPA giam dan  **\n";
                cout << "                                        ** 3.Sap xep theo lop           **\n";
                cout << "                                        ** 4.Quay ve menu chinh         **\n";
                cout << "                                        ----------------------------------\n";
                cout << "                                           Lua chon cua ban: ";  cin >> n1;
                cout << endl;
                if( n1 == "1")
                {
                    sap_xep_theo_ten(v);
                    goto lap3;
                }
                else if( n1 == "2")
                {
                    sap_xep_theo_GPA(v);
                    goto lap3;
                }
                else if(n1 == "3")
                {
                    sap_xep_theo_lop(v);
                    goto lap3;
                }
                else if(n1 == "4"){
                    system("cls");
                    goto lap1;
                }
                else 
                {
                    cout << "                                    Lua chon khong hop le!\n";
                    goto lap3;
                }
            }
            else hien_thi_dssv(v);
            break;
        case 7:
            if(v.size()>0)
            {
                cout << "                                        -----------Nhap lua chon----------\n";
                cout << "                                        ** 1.Thong ke theo lop          **\n";
                cout << "                                        ** 2.Thong ke theo nganh hoc    **\n";
                cout << "                                        ----------------------------------\n";
                cout << "                                           Lua chon cua ban: ";  cin >> n1;
                cin.ignore();
                thong_ke(v, n1);
            }
            else cout << "                                           Danh sach sinh vien rong\n";
            break;
        case 8:

            v.resize(1000);
            input_file(v);
            for(int i = v.size()-1; i >= 0; i--)
            {
                if(v[i].gpa == 0)
                    v.pop_back();
            } 
            sap_xep_theo_ten(v);
            cout << "                                        Them thanh cong sinh vien tu file DSSV.txt.\n";
            break;
        case 9:
            output_file(v);
            break;
        case 10:
            cout << "                                         Day la dinh dang file chuan:\n\n";
            cout << "                                               Nguyen van A (ho ten)\n";
            cout << "                                               27001 (ma sinh vien)\n";
            cout << "                                               TH27.15 (ma lop)\n";
            cout << "                                               CNTT (nganh hoc)\n";
            cout << "                                               2/03/2004 (ngay sinh)\n";
            cout << "                                               ha noi (dia chi)\n";
            cout << "                                               3.8 (diem gpa)\n";
            cout << "                                               Nguyen van b\n";
            cout << "                                               27002\n";
            cout << "                                               QT27.15\n";
            cout << "                                               QTKD\n";
            cout << "                                               04/02/2004\n";
            cout << "                                               ha tay\n";
            cout << "                                               3.8\n";
            cout << "                                               ...\n\n";
            cout << "                                        LUU Y: thong tin sinh vien bat dau bang ho ten va ket thuc bang diem gpa\n";
            cout << "                                               trong do 'Nguyen van A' la ho ten sinh vien, nhung phan trong () la chu thich\n";
            break;
        }

        cout << endl << endl ;
        check = false;
        pw3(check, pw_m);
        cout << endl << "                                        Nhan phim bat ky de tiep tuc... ";
        getch();
        system("cls");
    }
    return 0;
}