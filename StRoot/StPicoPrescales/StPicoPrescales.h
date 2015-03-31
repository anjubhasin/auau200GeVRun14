/* 
 * Author: Mustafa Mustafa (mmustafa@lbl.gov)
 */

#ifndef StPRESCALES_H
#define	StPRESCALES_H

#include <map>
#include <vector>

class TH1F;

class StPicoPrescales
{
  public:
    static StPicoPrescales const* instance();

    float getPrescale(unsigned int run,unsigned int trg);
    unsigned int runIndex(unsigned int run);
    bool runExists(unsigned int run);
    int getNumberOfRuns() const;
    void fillPrescalesHist(TH1F*,unsigned int trg);

  protected:
    StPicoPrescales();

  private:
    static StPicoPrescales* mInstance;

    typedef std::vector<float> vecPrescales;
    std::map<unsigned int,vecPrescales> mTable;
    std::map<unsigned int,vecPrescales>::iterator mLastQuery;

    void readList(unsigned int trg);

    ClassDef(StPicoPrescales,1)
};

#endif	/* StPRESCALES_H */

