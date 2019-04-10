/* This file is generated by tdr. */
/* No manual modification is permitted. */

/* tdr version: 2.7.16 */

#ifndef TSF4G_TDR_TDR_TIME_H_
#define TSF4G_TDR_TDR_TIME_H_

#include "TdrPal.h"
#include "TdrBuf.h"
#include "TdrError.h"

namespace tsf4g_tdr
{


union TdrDateOrTimeUi16
{
    tdr_time_t time;
    tdr_date_t date;
    uint16_t ui16;
};

#pragma pack(1)
struct TdrStructDateTime
{
    tdr_date_t date;
    tdr_time_t time;
};
#pragma pack()

union TdrUnionDateTime
{
    tdr_datetime_t entirety;
    TdrStructDateTime sections;
};

inline uint16_t tdrGetHourOfTime(const tdr_time_t time)
{
    TdrDateOrTimeUi16 t2i;

    t2i.time = time;

    return t2i.ui16;
}

inline uint16_t tdrGetYearOfDate(const tdr_date_t date)
{
    TdrDateOrTimeUi16 d2i;

    d2i.date = date;

    return d2i.ui16;
}

inline tdr_time_t tdrSetHour2Time(const uint16_t hour)
{
    TdrDateOrTimeUi16 i2t;

    i2t.ui16 = hour;

    return i2t.time;
}

inline tdr_date_t tdrSetYear2Date(const uint16_t year)
{
    TdrDateOrTimeUi16 i2d;

    i2d.ui16 = year;

    return i2d.date;
}

inline void tdrSetDate2Datetime(tdr_datetime_t& datetime, const tdr_date_t date)
{
    TdrUnionDateTime sections2entirety;

    sections2entirety.entirety = datetime;

    sections2entirety.sections.date = date;

    datetime = sections2entirety.entirety;
}

inline void tdrSetTime2Datetime(tdr_datetime_t& datetime, const tdr_time_t time)
{
    TdrUnionDateTime sections2entirety;

    sections2entirety.entirety = datetime;

    sections2entirety.sections.time = time;

    datetime = sections2entirety.entirety;
}

inline tdr_date_t tdrGetDateOfDatetime(const tdr_datetime_t datetime)
{
    TdrUnionDateTime entirety2sections;

    entirety2sections.entirety = datetime;

    return entirety2sections.sections.date;
}

inline tdr_time_t tdrGetTimeOfDatetime(const tdr_datetime_t datetime)
{
    TdrUnionDateTime entirety2sections;

    entirety2sections.entirety = datetime;

    return entirety2sections.sections.time;
}


class TdrTime
{
    private:
        int16_t nHour;
        uint8_t bMin;
        uint8_t bSec;

    public:
        TdrTime(struct tm& src)
        {
            nHour = (short)src.tm_hour;
            bMin = (unsigned char)src.tm_min;
            bSec = (unsigned char)src.tm_sec;
        }

        TdrTime(tdr_time_t src)
        {
            nHour = tdrGetHourOfTime(src);
            bMin = *(uint8_t*)((char*)&src + 2);
            bSec = *(uint8_t*)((char*)&src + 3);
        }

        void toTm(struct tm& dest) const
        {
            dest.tm_hour = nHour;
            dest.tm_min  = bMin;
            dest.tm_sec  = bSec;
        }

        operator tdr_time_t () const
        {
            tdr_time_t ret = 0;

            ret = tdrSetHour2Time(nHour);
            *(uint8_t*)((char*)&ret + 2) = bMin;
            *(uint8_t*)((char*)&ret + 3) = bSec;

            return ret;
        }

        TdrError::ErrorType print2Buf(TdrWriteBuf& dest) const
        {
            return dest.textize("%02d:%02d:%02d", nHour, bMin, bSec);
        }

        TdrError::ErrorType print2Buf(char* dest, size_t size, int *usedSize) const
        {
            if (NULL == dest || size <= 0)
            {
                return TdrError::TDR_ERR_NULL_POINTER_PARAMETER;
            }
            *usedSize = tdr_cpp_snprintf(dest, size, "%02d:%02d:%02d", nHour, bMin, bSec);

            return TdrError::TDR_NO_ERROR;
        }

        bool operator < (const TdrTime& right) const
        {
            if (this->nHour > right.nHour)
            {
                return false;
            } else if (this->nHour < right.nHour)
            {
                return true;
            }

            if (this->bMin > right.bMin)
            {
                return false;
            } else if (this->bMin < right.bMin)
            {
                return true;
            }

            if (this->bSec > right.bSec)
            {
                return false;
            } else if (this->bSec < right.bSec)
            {
                return true;
            }

            return false;
        }

        bool isValid() const
        {
            if ((-999 > nHour) || (999 < nHour))
            {
                return false;
            }

            if ((59 < bMin))
            {
                return false;
            }

            if ((59 < bSec))
            {
                return false;
            }

            return true;
        }
};

class TdrDate
{
    private:
        int16_t nYear;
        uint8_t bMon;
        uint8_t bDay;

    public:
        TdrDate(struct tm& src)
        {
            nYear = (short)(src.tm_year + 1900);
            bMon = (unsigned char)src.tm_mon + 1;
            bDay = (unsigned char)src.tm_mday;
        }

        TdrDate(tdr_date_t src)
        {
            nYear = tdrGetYearOfDate(src);
            bMon = *(uint8_t*)((char*)&src + 2);
            bDay = *(uint8_t*)((char*)&src + 3);
        }

        void toTm(struct tm& dest) const
        {
            dest.tm_year = nYear - 1900;
            dest.tm_mon  = bMon - 1;
            dest.tm_mday = bDay;
        }

        operator tdr_date_t () const
        {
            tdr_date_t ret = 0;

            ret = tdrSetYear2Date(nYear);
            *(uint8_t*)((char*)&ret + 2) = bMon;
            *(uint8_t*)((char*)&ret + 3) = bDay;

            return ret;
        }

        TdrError::ErrorType print2Buf(TdrWriteBuf& dest) const
        {
            return dest.textize("%4d-%02d-%02d", nYear, bMon, bDay);
        }

        TdrError::ErrorType print2Buf(char* dest, size_t size, int *usedSize) const
        {
            if (NULL == dest || size <= 0)
            {
                return TdrError::TDR_ERR_NULL_POINTER_PARAMETER;
            }
            *usedSize = tdr_cpp_snprintf(dest, size, "%4d-%02d-%02d", nYear, bMon, bDay);

            return TdrError::TDR_NO_ERROR;
        }

        bool operator < (const TdrDate& right) const
        {
            if (this->nYear > right.nYear)
            {
                return false;
            } else if (this->nYear < right.nYear)
            {
                return true;
            }

            if (this->bMon > right.bMon)
            {
                return false;
            } else if (this->bMon < right.bMon)
            {
                return true;
            }

            if (this->bDay > right.bDay)
            {
                return false;
            } else if (this->bDay < right.bDay)
            {
                return true;
            }

            return false;
        }

        bool isValid() const;
};

class TdrDateTime
{
    private:
        TdrDate tdrDate;
        TdrTime tdrTime;

    public:
        TdrDateTime(struct tm& src) : tdrDate(src), tdrTime(src) {}

        TdrDateTime(tdr_datetime_t src)
            : tdrDate(tdrGetDateOfDatetime(src)), tdrTime(tdrGetTimeOfDatetime(src)) {}

        operator tdr_datetime_t () const
        {
            tdr_datetime_t ret = 0;

            tdrSetDate2Datetime(ret, tdrDate);
            tdrSetTime2Datetime(ret, tdrTime);

            return ret;
        }

        void toTm(struct tm& dest) const
        {
            tdrDate.toTm(dest);
            tdrTime.toTm(dest);
        }

        TdrError::ErrorType print2Buf(TdrWriteBuf& dest) const
        {
            TdrError::ErrorType ret = TdrError::TDR_NO_ERROR;

            ret = tdrDate.print2Buf(dest);

            if (TdrError::TDR_NO_ERROR == ret)
            {
                ret = dest.writeChar(' ');
            }

            if (TdrError::TDR_NO_ERROR == ret)
            {
                ret = tdrTime.print2Buf(dest);
            }

            return ret;
        }

        TdrError::ErrorType print2Buf(char* dest, size_t size, int *usedSize) const
        {
            TdrError::ErrorType ret = TdrError::TDR_NO_ERROR;

            if (NULL == dest || size <= 0)
            {
                return TdrError::TDR_ERR_NULL_POINTER_PARAMETER;
            }

            ret = tdrDate.print2Buf(dest, size, usedSize);
            if (ret != TdrError::TDR_NO_ERROR)
            {
                return ret;
            }

            if (*usedSize >= 0 && *usedSize <= (int)size )
            {
                dest[(*usedSize)++] = ' ';
            }

            if (*usedSize >= 0 && *usedSize <= (int)size )
            {
                ret = tdrTime.print2Buf(dest + *usedSize, size - *usedSize, usedSize);
            }

            return ret;
        }


        bool operator < (const TdrDateTime& right) const
        {
            if (this->tdrDate < right.tdrDate)
            {
                return true;
            } else if (right.tdrDate < this->tdrDate)
            {
                return false;
            }

            if (this->tdrTime < right.tdrTime)
            {
                return true;
            } else if (right.tdrTime < this->tdrTime)
            {
                return false;
            }

            return false;
        }

        bool isValid() const
        {
            return tdrDate.isValid() && tdrTime.isValid();
        }
};

}
#endif
