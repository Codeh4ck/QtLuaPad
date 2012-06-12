#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define APPVRSN "1.1"
#define APPNAME "QtLuaPad"
#define ORGNAME "Delirium"
#define ORGURL "http://otland.net/forum.php"
#define FALLENSPROF "http://otland.net/members/Fallen"
#define DELIRIUMSPROF "http://otland.net/members/Delirium"
#define CHOJRAKSPROF "http://otland.net/members/chojrak"

#ifdef assert
        #undef assert
#endif

#include <sstream>
/*
#include <cstdint>

#ifdef qApp
        #define assert(x)\
                if(!x)\
                {\
                        std::stringstream ss;\
                        ss << "Asseration to: " << #x << " failed. line: " << __LINE__ << ", file: " << __FILE__ << ". Continue?";\
                        uint32_t ret = QMessageBox::critical(NULL, QObject::tr("Error"), QObject::tr(ss.str().c_str()),\
                                QMessageBox::Ok | QMessageBox::Cancel);\
                        switch (ret)\
                        {\
                                case QMessageBox::Ok:\
                                        break;\
                                \
                                case QMessageBox::Cancel:\
                                        qApp->quit();\
                        }\
                }
#endif

#define QTLUAPAD_WARNING(x, y)\
        std::stringstream ss;\
        ss << "[Warning - " << #x << "] " << #y << ".";\
        QMessageBox::warning(NULL, QObject::tr("Warning"), QObject::tr(ss.str().c_str()));

#define QTLUAPAD_ERROR(x, y)\
        std::stringstream ss;\
        ss << "[Error - " << #x << "] " << #y << ".";\
        QMessageBox::critical(NULL, QObject::tr("Error"), QObject::tr(ss.str().c_str()));

#define QTLUAPAD_NOTICE(x, y)\
        std::stringstream ss;\
        ss << "[Notice - " << #x << "] " << #y << ".";\
        QMessageBox::information(NULL, QObject::tr("Notice"), QObject::tr(ss.str().c_str()));

template<typename __T>
inline void*
__construct(__T* __p)
{ return ::new(static_cast<void*>(__p)) __T(); }

template<typename __T>
inline void
__destruct(__T* __p)
{ assert(__p != 0); __p->~__T(); }

typedef size_t size_type;

template<typename __T>
inline __T*
__allocate(size_type __n, const void* = 0)
{ return static_cast<__T*>(::operator new(__n * sizeof(__T*))); }

template<typename __T>
inline void
__deallocate(__T* __p)
{ ::operator delete(__p); }
*/
#endif // DEFINITIONS_H
