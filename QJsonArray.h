
#ifndef QJSON_ARRAY_H_
#define QJSON_ARRAY_H_

#include <QtCore/QtGlobal>

#if QT_VERSION >= 0x050000
#include <QtCore/QJsonArray>
#else

#include "QJsonRoot.h"
#include <QtCore/QList>
#include <QtCore/QVariantList>

class QJsonValue;
class QJsonValueRef;

class QJsonArray : public QJsonRoot {
	friend class QJsonDocument;
	friend class QJsonValue;
	friend class QJsonParser;
public:
	// TODO: manually implement the array, for now we use QList
	//       but the real thing has a custom implementation
	//       I guess for the purposes of less interdependancies?
	//       maybe so it's easier to forward declare the iterators?
	typedef QList<QJsonValue>::const_iterator  const_iterator;
	typedef QList<QJsonValue>::iterator        iterator;
	typedef	const_iterator                       ConstIterator;
	typedef	iterator                             Iterator;
	typedef	QList<QJsonValue>::const_pointer   const_pointer;
	typedef	QList<QJsonValue>::const_reference const_reference;
	typedef	QList<QJsonValue>::difference_type difference_type;
	typedef	QList<QJsonValue>::pointer         pointer;
	typedef	QList<QJsonValue>::reference       reference;
	typedef	QList<QJsonValue>::size_type       size_type;
	typedef	QList<QJsonValue>::value_type      value_type;

public:
	QJsonArray();
	QJsonArray(const QJsonArray &other);
	~QJsonArray();

public:
	QJsonArray &operator=(const QJsonArray &other);

public:
	bool operator!=(const QJsonArray &other) const;
	bool operator==(const QJsonArray &other) const;

public:
	const_iterator begin() const;
	const_iterator end() const;
	iterator begin();
	iterator end();
	const_iterator constBegin() const;
	const_iterator constEnd() const;

public:
	QJsonValueRef operator[](int i);
	QJsonValue operator[](int i) const;
	QJsonValue at(int i) const;
	QJsonValue first() const;
	QJsonValue last() const;

public:
	int size() const;
	int count() const;
	bool empty() const;
	bool isEmpty() const;

public:
	void pop_back();
	void pop_front();
	void push_back(const QJsonValue &value);
	void push_front(const QJsonValue &value);

public:
	void append(const QJsonValue &value);
	bool contains(const QJsonValue &value) const;
	iterator erase(iterator it);
	void insert(int i, const QJsonValue &value);
	iterator insert(iterator before, const QJsonValue &value);
	void prepend(const QJsonValue &value);
	void removeAt(int i);
	void removeFirst();
	void removeLast();
	void replace(int i, const QJsonValue &value);
	QJsonValue takeAt(int i);
	
public:
	QVariantList toVariantList() const;
	
public:
	static QJsonArray fromStringList(const QStringList &list);
	static QJsonArray fromVariantList(const QVariantList &list);

private:
	virtual QJsonRoot *clone() const;
	virtual QJsonArray *toArray();
	virtual QJsonObject *toObject();
	virtual const QJsonArray *toArray() const;
	virtual const QJsonObject *toObject() const;

private:
	void swap(QJsonArray &other);

private:
	QList<QJsonValue> values_;
};

#endif

#endif