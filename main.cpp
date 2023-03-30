#include <iostream>

using namespace std;

class AbstractSkillWillStudent {
    protected:
        string FirstName;
        string LastName;
        string Teach;
        int Age;
        string Section;
        string Course;
        double QuizScore;
        double LastQuizScore;
        
    public:
    
        string getFirstName(){
            return FirstName;
        }
        
        void setFirstName(string FirstName){
            this -> FirstName = FirstName;
        }
        
        string getLastName(){
            return LastName;
        }
        
        void setLastName(string LastName){
            this -> LastName = LastName;
        }
    
        string getTeach(){
            return Teach;
        }
        
        void setTeach(){
            this -> Teach = Teach;
        }
    
        int getAge(){
            return Age;
        }
    
        void setAge(int NewAge){
            this -> Age = Age;
        }
         string getSection(){
            return Section;
        }
        
        void setSection(string Section){
            this -> Section = Section;
        }
        
        string getCourse(){
            return Course;
        }
        
        void setCourse(string Course){
            this -> Course = Course;
        }
        
        double getQuizScore(){
            return QuizScore;
        }
        
        void setQuizScore(double QuizScore){
            this -> QuizScore = QuizScore;
        }
        
         double getLastQuizScore(){
            return LastQuizScore;
        }
        
        void setLastQuizScore(double LastQuizScore){
            this -> LastQuizScore = LastQuizScore;
        }
        
    
        AbstractSkillWillStudent(string FirstName, string LastName ,string Teach, int Age){
            this -> FirstName = FirstName;
            this -> LastName = LastName;
            this -> Teach = Teach;
            this -> Age = Age;
        }
    
       
        virtual void studentInfo ()=0; 
        void AttendingLecture () {
            cout << "The student attends the lecture" ;  
        }
        
        
};

class AbstractSubject {
    protected:
    string Name;
    string DurationOfTheCourse;
    string StartDate;
    string LastLectureName;
    public:
    
    string getName() {
        return Name;
    } 
    
    void setName(string Name) {
        this -> Name = Name;
        }
        
        string getDurationOfTheCourse() {
            return DurationOfTheCourse;
        }
        
        void setDurationOfTheCourse( string DurationOfTheCourse) {
            this -> DurationOfTheCourse = DurationOfTheCourse;
        }
        
        string getStartDate() {
            return StartDate;
        }
        void setStartDate (string StartDate) {
            this -> StartDate = StartDate;
        }
        
        string getLastLectureName(){
            return LastLectureName;
        }
        
        void setLastLectureName(string LastLectureName){
            this -> LastLectureName = LastLectureName;
        }
        
        AbstractSubject(string Name,string DurationOfTheCourse,string StartDate){
            this -> Name = Name ;
            this -> DurationOfTheCourse = DurationOfTheCourse;
            this -> StartDate = StartDate;
        }
        
        virtual void LastLecture()=0;
        void AboutCourse(){
         cout << "Information About Course "<<endl;  
        }
   
};
// Abstract class for a lecture
class Lecture {
protected:
    string firstName;
    string lastName;
    string SubjectName;

public:
    virtual string getFirstName() = 0;
    virtual void setFirstName(string firstName) = 0;
    virtual string getLastName() = 0;
    virtual void setLastName(string lastName) = 0;
    virtual string getSubjectName() = 0;
    virtual void setSubjectName(string SubjectName) = 0;
    
    virtual string PerformLecture(int chapter, string date){
        string message="is giving a lecture";
        cout<<message<<endl;
        return message;
    }
    
   
Lecture (string firstName, string lastName, string SubjectName) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->SubjectName = SubjectName;
    };

};
//SkillwillLecturer class

class SkillwillLecturer : public Lecture {
private: 
    int chapter;
    int level;
    
public:

SkillwillLecturer(string firstName, string lastName, string SubjectName, int chapter, int level): Lecture(firstName, lastName, SubjectName){
    this->chapter=chapter;
    this->level=level;
}

    string getFirstName()  {
        return firstName;
    }
    void setFirstName(string firstName)  {
        this->firstName = firstName;
    }
    string getLastName()  {
        return lastName;
    }
    void setLastName(string lastName)  {
        this->lastName = lastName;
    }
    string getSubjectName(){
        return SubjectName;
    }
    void setSubjectName(string SubjectName){
        this->SubjectName = SubjectName;
    }
    
    int getChapter() {
        return chapter;
    }
    void setChapter(int chapter) {
        this->chapter = chapter;
    }
    int getLevel() {
        return level;
    }
    void setLevel(int level) {
        this->level = level;
    }
    string PerformLecture(int chapter, string date){
        string fullName=firstName+" "+lastName;
        cout<<fullName<<" is giving a lecture "<<endl;
        return fullName;
    }
     void lectureInfo (){
            cout<< "First Name : " << getFirstName()<<endl;
            cout<<"Last Name : "<< getLastName()<<endl;
            cout<<"SubjectName : "<<getSubjectName()<<endl;
            cout<<"chapter : "<< getChapter()<<endl;
            cout<<"level : " << getLevel()<< endl; 
        } 
    
};

    
class SkillWill: public AbstractSkillWillStudent , public AbstractSubject {
 
    public:
        SkillWill (string FirstName, string LastName ,string Teach, int Age,string Name,string DurationOfTheCourse,string StartDate): AbstractSkillWillStudent (FirstName,LastName,Teach,Age),AbstractSubject(Name, DurationOfTheCourse, StartDate){}
      
       
        void studentInfo (){
            cout<< "First Name : " << getFirstName()<<endl;
            cout<<"Last Name : "<< getLastName()<<endl;
            cout<<"Course : "<<getTeach()<<endl;
            cout<<"Age : "<< getAge()<<endl;
        }  
        
         void StudentStudyAndScore(){
             cout << getFirstName()<< " "<< getLastName() << " is student of " << getTeach() <<" in Section "<< getSection() <<endl;
            cout << "student got " << getQuizScore() << " points in the quiz for the month" << endl;
         }
      
         void Update(){
            cout<<"Student"<<endl;
            cout<< "First Name : "<< getFirstName()<<endl;
            cout<<"Last Name : "<<getLastName()<<endl;
            cout<<"The final result of the quiz :"<<endl;
            cout<< getLastQuizScore() <<endl;
        }
    
        
        void AttendingLecture (string FirstName, string LastName, int chapter) {
          cout << getFirstName()<< " "<< getLastName() << " is attending lecture " << endl;  // აქ საბჯექთიდან წამოვა საგანი//
        }
        
         void LastLecture(){
            cout << "The title of the last lecture is "<<getLastLectureName();
        }
        
        void AboutCourse(){
            cout<<"Course Name : "<< getName()<<endl;
            cout<<"Duration of the course : "<< getDurationOfTheCourse()<<endl;
            cout<<"Start Date : " << getStartDate()<<endl;
        }
      
        
};
    

int main()
{
   
      //სტუდენტი სახელი გვარი სურსი ასაკი
   
  SkillWill student("Giorgi","Pkhakadze","Web",29,"FrontEnd","3 Month","30 March");
  student.studentInfo();
  //ლექტორის  მონაცემები
   SkillwillLecturer l= SkillwillLecturer("ana", "gogua","Web", 1,1);
  // l.lectureInfo();
   
   //ლექტორი ატარებს ლექციას
   l.PerformLecture(1,"01.11.2022");
   
   //სტუდენტი ესწრება ლექციას
   student.AttendingLecture("Giorgi","Pkhakadze",1);
   
  //სტუდენტი  რომელ სექციაზეა კურსზე ქულა
  
 //student.setSection("C");
 //student.setQuizScore(36);
 //student.StudentStudyAndScore();

// სტუდენტი საბოლოო ქულა

//student.setLastQuizScore(70);
//student.Update();
   
    //ინფორმაცია კურსზე
// student.AboutCourse();
   
   //ბოლო ლექციის სახელი
    student.setLastLectureName("'Learn Javascript'");
    student.LastLecture();
   
    return 0;
}

