/**
 * @file
 * @deprecated
 */
#pragma once

#include <string>

class Message
{
private:
	MessageObject object;

protected:
	virtual std::string code = "00|";

public:
	Message(MessageObject obj) : object(obj) { }

	std::string ToSend()
	{
		return code + object.ToMessage();
	}

	MessageObject GetObject(const std::string & msg)
	{
		return MessageObject::FromMessage(std::string(msg, 3, msg.length - 3));
	}
};

class MessageObject
{
public:
	virtual std::string ToMessage()
	{
		return "";
	}

	static virtual MessageObject FromMessage(const std::string & msg)
	{
		return new MessageObject();
	}
};