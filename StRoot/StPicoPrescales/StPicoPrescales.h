/* 
 * Author: Mustafa Mustafa (mmustafa@lbl.gov)
 */

#ifndef StPRESCALES_H
#define	StPRESCALES_H

#include <map>
#include <vector>
#include <string>

class TH1F;

class StPicoPrescales
{
  public:
    StPicoPrescales(std::string prescalesFilesDirectoryName);

    float getPrescale(unsigned int run,unsigned int trg);
    unsigned int runIndex(unsigned int run);
    bool runExists(unsigned int run);
    int getNumberOfRuns() const;
    void fillPrescalesHist(TH1F*,unsigned int trg);

  private:
    std::string mPrescalesFilesDirectoryName;
    std::vector<unsigned int> mTriggersIds;
    typedef std::vector<float> vecPrescales;
    std::map<unsigned int,vecPrescales> mTable;
    std::map<unsigned int,vecPrescales>::iterator mLastQuery;

    void readList(unsigned int trgId);

    ClassDef(StPicoPrescales,1)
};

#endif	/* StPRESCALES_H */

