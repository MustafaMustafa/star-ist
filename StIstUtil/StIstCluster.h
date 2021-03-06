/***************************************************************************
*
* $Id: StIstCluster.h,v 1.11 2014/09/09 08:23:46 ypwang Exp $
*
* Author: Yaping Wang, March 2013
****************************************************************************
* Description:
* Data structure for IST cluster (neighboring pads fired by the same track).
****************************************************************************/

#ifndef StIstCluster_hh
#define StIstCluster_hh

#include <map>

#include "StObject.h"
#include "StIstRawHit.h"

class StIstCluster: public TObject
{
public:

   StIstCluster(int key = -1, int ladder = -1, int sensor = -1,
                float meanRow = -1, float meanColumn = -1, float totCharge = 0,
                float totChargeErr = 0, int clusteringType = -1);
   ~StIstCluster();

   //accessors
   vector<StIstRawHit *> &getRawHitVec();
   const vector<StIstRawHit *> &getRawHitVec() 	const;
   int                  getKey()            	const;
   unsigned char        getLadder()         	const; //!< 1-24
   unsigned char        getSensor()         	const; //!< 1-6
   float                getMeanRow()        	const;
   float                getMeanColumn()     	const;
   float                getTotCharge()      	const;
   float                getTotChargeErr()   	const;
   unsigned char        getMaxTimeBin()     	const;
   unsigned char        getClusteringType() 	const;
   unsigned char        getNRawHits()       	const;
   unsigned char        getNRawHitsRPhi()   	const;
   unsigned char        getNRawHitsZ()      	const;
   unsigned short       getIdTruth()        	const;

   void        setLadder(int ladder);
   void        setSensor(int sensor);
   void        setMeanRow(float meanRow);
   void        setMeanColumn(float meanColumn);
   void        setTotCharge(float totCharge);
   void        setTotChargeErr(float totChargeErr);
   void        setMaxTimeBin(int tb);
   void        setClusteringType(int clusteringType);
   void        setNRawHits(int nRawHits);
   void        setNRawHitsRPhi(int nRawHitsRPhi);
   void        setNRawHitsZ(int nRawHitsZ);
   void        setIdTruth(unsigned short idTruth);

   virtual void Print(Option_t *opt = "") const;

protected:
   Int_t       mKey;                    	///< Cluster unique label
   Float_t     mMeanRow;                	///< Cluster's mean row
   Float_t     mMeanColumn;             	///< Cluster's mean column
   Float_t     mTotCharge;              	///< Charge sum of the cluster
   Float_t     mTotChargeErr;           	///< rMS noise of the cluster
   UShort_t    mIdTruth;                        //!< For embedding, 0 as background
   UChar_t     mLadderId;                       ///< Ladder id the cluster belongs to
   UChar_t     mSensorId;                       ///< Sensor id the cluster belongs to
   UChar_t     mClusteringType;         	///< Clustering algorithm type
   UChar_t     mMaxTimeBin;             	///< Max ADC time bin index
   UChar_t     mNRawHits;               	///< Cluster size
   UChar_t     mNRawHitsRPhi;           	///< Cluster size in r-phi direction
   UChar_t     mNRawHitsZ;              	///< Cluster size in beam direction
   std::vector<StIstRawHit *> mRawHitVec;	///< Map container to save raw hits who contribute to the cluster

   ClassDef(StIstCluster, 1);
};

#endif


/***************************************************************************
*
* $Log: StIstCluster.h,v $
* Revision 1.11  2014/09/09 08:23:46  ypwang
* all unsgined char was updated to int type as Victor P. suggested
*
* Revision 1.10  2014/09/08 19:06:57  smirnovd
* Added Print() methods to print out properties of StIstCluster and StIstRawHit objects and their respective collections
*
* Revision 1.9  2014/03/27 22:46:47  smirnovd
* Updated broken style with astyle -s3 -p -H -A3 -k3 -O -o -y -Y -f
*
* Revision 1.8  2014/02/15 01:16:18  ypwang
* replace the std::map() with std::vector() for StIstCluster
*
* Revision 1.7  2014/02/13 02:35:49  smirnovd
* Moved CVS log to the bottom of the file
*
* Revision 1.6  2014/02/10 16:34:22  smirnovd
* Use constructor initialization list, other nit-picks
*
* Revision 1.5  2014/02/10 16:34:09  smirnovd
* Addressed minor doxygen and style issues
*
* Revision 1.4  2014/02/10 16:33:46  smirnovd
* Trimmed trailing spaces, expanded tabs to eight spaces
*
* Revision 1.3  2014/02/03 16:12:20  ypwang
* updating scripts
*
*
****************************************************************************
* StIstCluster.h,v 1.0
* Revision 1.0 2013/11/04 15:15:30 Yaping
* Initial version
****************************************************************************/
