#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "illness.h"
#include "patient.h"
#include "hcp.h"
#include<iostream>
#include<string>
#include<memory>
#include<stdexcept>
#include<set>
#include<map>
#include<vector>

class Hospital {
    std::string name;
    std::map<std::string,std::shared_ptr<Health_Care_Provider>> hcps;
    std::map<std::string,std::weak_ptr<Patient>> patients;
    public: 
        Hospital(std::string name);
        bool sign_hcp(std::shared_ptr<Health_Care_Provider> m);
        bool admit_patient(std::shared_ptr<Patient> m);
        bool dismiss_hcp(std::string n);
        std::shared_ptr<Health_Care_Provider> get_hcp(std::string n) const;
        std::shared_ptr<Patient> get_patient(std::string n) const;
        bool dismiss_patient(std::string n);
        friend std::ostream& operator<<(std::ostream& o, const Hospital& p);
};

#endif