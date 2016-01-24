#ifndef __FOLDER_H
#define __FOLDER_H

#include "library_item.h"

#include <QList>

class Folder : public LibraryItem
{
public:
	bool knownParent;
	bool knownId;
	
    Folder();
    Folder(qulonglong folderId, qulonglong parentId,const QString & folderName, const QString & folderPath);
    Folder(const QString & folderName, const QString & folderPath);

    inline void setId(qulonglong sid)
    {
        id = sid;
        knownId = true;
    }

    inline void setFather(qulonglong pid)
    {
        parentId = pid;
        knownParent = true;
    }

    inline bool isDir() const
    {
        return true;
    }

    inline bool isFinished() const
    {
        return finished;
    }

    inline bool isCompleted() const
    {
        return completed;
    }

    inline void setFinished(bool b)
    {
        finished = b;
    }

    inline void setCompleted(bool b)
    {
        completed = b;
    }

    inline qint32 getNumChildren() const
    {
        return numChildren;
    }

    inline void setNumChildren(const qint32 v)
    {
        numChildren = v;
    }

    inline qulonglong getFirstChildId() const
    {
        return firstChildId;
    }

    inline void setFirstChildId(const qulonglong v)
    {
        firstChildId = v;
    }

    inline qulonglong getCustomImage() const
    {
        return firstChildId;
    }

    inline void setCustomImage(const QString & s)
    {
        customImage = s;
    }

private:
    bool finished;
    bool completed;

    qint32 numChildren; //-1 for unknown number of children
    qulonglong firstChildId; //0 for unknown first child
    QString customImage; //empty for none custom image

};

#endif
