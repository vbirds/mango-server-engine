/* This file is generated by tdr. */
/* No manual modification is permitted. */

/* tdr version: 2.7.16 */

#ifndef TSF4G_TDR_TDR_IO_H_
#define TSF4G_TDR_TDR_IO_H_

#include "TdrPal.h"
#include "TdrBuf.h"
#include "TdrError.h"

namespace tsf4g_tdr
{


class TdrXmlFile
{
    private:
        char*   _buffer;

    private:
        TdrError::ErrorType _state;

    private:
        TdrError::ErrorType load(const char* file);

    public:
        TdrXmlFile(const char* file)
            : _buffer(NULL), _state(TdrError::TDR_NO_ERROR)
        {
            assert(NULL != file);

            _state = load(file);
        }

        ~TdrXmlFile()
        {
            if (NULL != _buffer)
            {
                delete[] _buffer;
                _buffer = NULL;
            }
        }

    public:
        TdrError::ErrorType state() const
        {
            return _state;
        }

        char* content()
        {
            assert(TdrError::TDR_NO_ERROR == _state);

            return _buffer;
        }
};

class TdrOutStream
{
    private:
        FILE* _fp;
        TdrWriteBuf _buf;

    private:
        TdrError::ErrorType _state;

    public:
        TdrError::ErrorType state() const
        {
            return _state;
        }

    public:
        size_t getUsedSize() const
        {
            assert(NULL == _fp);

            return _buf.getUsedSize();
        }

    public:
        TdrOutStream(FILE* fp) : _fp(fp), _state(TdrError::TDR_NO_ERROR) {}

        TdrOutStream(char* ptr, size_t size)
            : _fp(NULL), _buf(ptr, size), _state(TdrError::TDR_NO_ERROR) {}

    public:
        TdrError::ErrorType vtextize(const char* format, va_list ap);

        TdrError::ErrorType textize(const char* format, ...)
        {
            assert(TdrError::TDR_NO_ERROR == _state);
            assert(NULL != format);

            va_list ap;

            va_start(ap, format);
            _state = vtextize(format, ap);
            va_end(ap);

            return _state;
        }

    public:
        TdrError::ErrorType output(const char* src, size_t length);
};

}
#endif
