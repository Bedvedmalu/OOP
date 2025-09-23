#pragma once
#include "students.h"

class GroupLeader : public Student {
private:
	std::wstring position;
	std::wstring phone_number;
public:
	GroupLeader();
	GroupLeader(int student_id, std::wstring& first_name, std::wstring& second_name, int age, std::wstring& group, std::wstring& position, std::wstring& phone_number);

	void readFromConsole() override;

	void writeToConsole() const override;

	template<class Archive>
	void serialize(Archive& ar, const unsigned int version) {
		ar& boost::serialization::base_object<Student>(*this);
		ar& position;
		ar& phone_number;
	}
};

BOOST_CLASS_EXPORT_KEY(GroupLeader)