#ifndef StPicoHFEvent__h
#define StPicoHFEvent__h
#ifdef __ROOT__

/* **************************************************
 *  Generic class storing event-wise information in HF analysis
 *   constructor takes option mode
 *     mode 0 : primary pair (default)        : StPicoHFEvent::pair
 *     mode 1 : primary triplet               : StPicoHFEvent::triplet
 *     mode 2 : primary pair + secondary pair : StPicoHFEvent::secondPair
 *
 *  Authors:  Xin Dong        (xdong@lbl.gov)
 *            Michael Lomnitz (mrlomnitz@lbl.gov)
 *            Mustafa Mustafa (mmustafa@lbl.gov)
 *            Jochen Thaeder  (jmthader@lbl.gov)   
 *
 * **************************************************
 */

class StPicoEvent;

#include "TObject.h"
#include "TClonesArray.h"

class StHFPair;
class StHFSecondaryPair;
class StHFTriplet;

class StPicoHFEvent : public TObject
{
public:
   StPicoHFEvent();
   StPicoHFEvent(unsigned int mode);
   ~StPicoHFEvent(){ clear("C");}
   void    clear(char const *option = "");
   void    addPicoEvent(StPicoEvent const & picoEvent);

   void    addHFPrimary(StHFPair const*);
   void    addHFPrimary(StHFTriplet const*);
   void    addHFSecondary(StHFSecondaryPair const*);

   inline TClonesArray const * hFPrimaryArray()     const;
   int                  nHFPrimary()         const;
   inline TClonesArray const * hFSecondaryArray()     const ;
   int                  nHFSecondary()       const;

   // for variables from StPicoEvent
   Int_t   runId()   const;
   Int_t   eventId() const;

   enum eHFEventMode {pair, triplet, secondaryPair};

private:

   // some variables below are kept in ROOT types to match the same ones in StPicoEvent
   Int_t   mRunId;           // run number
   Int_t   mEventId;         // event number
   int     mNHFPrimary;      // number of stored primary combinations
   int     mNHFSecondary;    // number of stored secondary combinations

   TClonesArray*        mHFPrimaryArray;
   static TClonesArray* fgHFPrimaryArray;

   TClonesArray*        mHFSecondaryArray;
   static TClonesArray* fgHFSecondaryArray;

   ClassDef(StPicoHFEvent, 1)
};

inline TClonesArray const * StPicoHFEvent::hFPrimaryArray()    const { return mHFPrimaryArray;}
inline int                  StPicoHFEvent::nHFPrimary()        const { return mNHFPrimary; }
inline TClonesArray const * StPicoHFEvent::hFSecondaryArray()  const { return mHFSecondaryArray;}
inline int                  StPicoHFEvent::nHFSecondary()      const { return mNHFSecondary; }

inline Int_t StPicoHFEvent::runId()        const { return mRunId; }
inline Int_t StPicoHFEvent::eventId()      const { return mEventId; }

#endif
#endif
