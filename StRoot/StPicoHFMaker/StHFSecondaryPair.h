#ifndef StHFSecondaryPair_hh
#define StHFSecondaryPair_hh
#ifdef __ROOT__

/* **************************************************
 *  Generic class calculating and storing secondary pairs in HF analysis
 *
 *  Authors:  Xin Dong        (xdong@lbl.gov)
 *            Michael Lomnitz (mrlomnitz@lbl.gov)
 *            Mustafa Mustafa (mmustafa@lbl.gov)
 *            Jochen Thaeder  (jmthader@lbl.gov)   
 *
 * **************************************************
 */

#include "TObject.h"
#include "TClonesArray.h"
#include "StLorentzVectorF.hh"

class StPicoTrack;

class StHFSecondaryPair : public TObject
{
 public:
  StHFSecondaryPair();
  StHFSecondaryPair(StHFSecondaryPair const *);

  StHFSecondaryPair(StPicoTrack const * particle1, StPicoTrack const * particle2, 
	   float p1MassHypo, float p2MassHypo,
	   unsigned short particle1Idx, unsigned short particle2Idx,
	   StThreeVectorF const & vtx, float bField);

  StHFSecondaryPair(StPicoTrack const * particle1, StHFSecondaryPair const * particle2, 
	   float p1MassHypo, float p2MassHypo,
	   unsigned short particle1Idx, unsigned short particle2Idx,
	   StThreeVectorF const & vtx, float bField);

  ~StHFSecondaryPair() {;}
  //Added method to update info using reconstructed secondary v0 in pair maker
  void UpdateVertex(StPicoTrack const * secondaryP1, StPicoTrack const * secondaryP2, StThreeVectorF const & vtx2);

  StLorentzVectorF const & lorentzVector() const { return mLorentzVector;}
  float m()    const;
  float pt()   const;
  float eta()  const;
  float phi()  const;
  float pointingAngle() const;
  float decayLength() const;
  float particle1Dca() const;
  float particle2Dca() const;
  unsigned short   particle1Idx() const;
  unsigned short   particle2Idx() const;
  float dcaDaughters() const;
  float cosThetaStar() const;
  //Added by Lomnitz access to vertex info
  float v0x() const;
  float v0y() const;
  float v0z() const;
  //Added by Lomnitz access to momentum info
  float px() const;
  float py() const;
  float pz() const;
 private:
  // disable copy constructor and assignment operator by making them private (once C++11 is available in STAR you can use delete specifier instead)
  StHFSecondaryPair(StHFSecondaryPair const &);
  StHFSecondaryPair& operator=(StHFSecondaryPair const &);
  StLorentzVectorF mLorentzVector; // this owns four float only

  float mPointingAngle;
  float mDecayLength;
  float mParticle1Dca;
  float mParticle2Dca;

  unsigned short  mParticle1Idx; // index of track in StPicoDstEvent
  unsigned short  mParticle2Idx;

  float mDcaDaughters;
  float mCosThetaStar;

  //Added by Lomnitz to save reco vertex pos
  float mV0x;
  float mV0y;
  float mV0z;
  
  ClassDef(StHFSecondaryPair,1)
};

inline float StHFSecondaryPair::m()    const { return mLorentzVector.m();}
inline float StHFSecondaryPair::pt()   const { return mLorentzVector.perp();}
inline float StHFSecondaryPair::eta()  const { return mLorentzVector.pseudoRapidity();}
inline float StHFSecondaryPair::phi()  const { return mLorentzVector.phi();}
//Lomnitz: Added access to momentum information 
inline float StHFSecondaryPair::px() const {return mLorentzVector.px();}
inline float StHFSecondaryPair::py() const {return mLorentzVector.py();}
inline float StHFSecondaryPair::pz() const {return mLorentzVector.pz();}
//
inline float StHFSecondaryPair::pointingAngle() const { return mPointingAngle;}
inline float StHFSecondaryPair::decayLength()   const { return mDecayLength;}
inline float StHFSecondaryPair::particle1Dca()  const { return mParticle1Dca;}
inline float StHFSecondaryPair::particle2Dca()  const { return mParticle2Dca;}
inline unsigned short   StHFSecondaryPair::particle1Idx() const { return mParticle1Idx;}
inline unsigned short   StHFSecondaryPair::particle2Idx() const { return mParticle2Idx;}
inline float StHFSecondaryPair::dcaDaughters() const { return mDcaDaughters;}
inline float StHFSecondaryPair::cosThetaStar() const { return mCosThetaStar;}
//Lomnitz:  Added to access secondary vertex info
inline float StHFSecondaryPair::v0x() const { return mV0x;}
inline float StHFSecondaryPair::v0y() const { return mV0y;}
inline float StHFSecondaryPair::v0z() const { return mV0z;}
#endif
#endif

