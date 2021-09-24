/*****************************************************************//**
 * \file   4_heydayAITestQuestion.cpp
 * \brief  Contains example questions asked in heyday.ai Inc. Test
 *
 * \author Xuhua Huang
 * \date   September 2021
 *********************************************************************/

#include <iostream>
#include <string>

 /* Type of requirement: resource end point
  * Input: userID: string
  * Output: email address and profile picture URL
  * Hinge: both information available from 2 different external resources
  */

  /* Using forward declaration. */
  /* Do NOT need to recompile as long as class name doesn't change. */
class Resource {
public:
	/* Implementation of Resource class. */
	const bool infoAvailable(const std::string) {}
	const bool lookUpID(const std::string&) {}
};

/* Structure to contain user details. */
struct UserInfo {
public:
	/* Could also declare them private with
	 * public getters and setters with more verification.
	 */
	std::string _email;    // prefixed with _ to state they are internal
	std::string _picURL;

	/* Provide default and overloaded constructor. */
	UserInfo() : _email(""), _picURL("") {}
	UserInfo(std::string email, std::string picURL) : _email(email), _picURL(picURL) {}

private:
	/* Prevent compiler generating copy constructor. */
	UserInfo(const UserInfo&) = delete;
	// UserInfo(UserInfo) = delete;
};

/* Function to look up user information by userID. */
static UserInfo getUserInfobyID(const std::string& userID,
	Resource& idealResource,
	Resource& alterResource) {

	/* Suppose Resource::lookUpID returns a handler object to the internal info. */
	/* Assuming Resource class do not throw exceptions. */
	if (idealResource.infoAvailable(userID))
		return UserInfo(
			idealResource.lookUpID(userID).getEmail(),
			idealResource.lookUpID(userID).getPicURL()
		);
	else if (alterResource.infoAvailable(userID))
		return UserInfo(
			alterResource.lookUpID(userID).getEmail(),
			alterResource.lookUpID(userID).getPicURL()
		);
	else
		std::cout << "Error! Resource look up failed." << std::endl;
	/* Alternative: add information to logger. */
}