/****************************************************************************
* MeshLab                                                           o o     *
* A versatile mesh processing toolbox                             o     o   *
*                                                                _   O  _   *
* Copyright(C) 2005                                                \/)\/    *
* Visual Computing Lab                                            /\/|      *
* ISTI - Italian National Research Council                           |      *
*                                                                    \      *
* All rights reserved.                                                      *
*                                                                           *
* This program is free software; you can redistribute it and/or modify      *   
* it under the terms of the GNU General Public License as published by      *
* the Free Software Foundation; either version 2 of the License, or         *
* (at your option) any later version.                                       *
*                                                                           *
* This program is distributed in the hope that it will be useful,           *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU General Public License (http://www.gnu.org/licenses/gpl.txt)          *
* for more details.                                                         *
*                                                                           *
****************************************************************************/
/****************************************************************************
  History
$Log: sampleplugins.h,v $
Revision 1.2  2006/11/29 00:59:21  cignoni
Cleaned plugins interface; changed useless help class into a plain string

Revision 1.1  2006/09/25 09:24:39  e_cerisoli
add sampleplugins

****************************************************************************/

#ifndef SAMPLEFILTERGPUPLUGIN_H
#define SAMPLEFILTERGPUPLUGIN_H

#include <QObject>

#include <common/interfaces.h>

class ExtraSampleGPUPlugin : public QObject, public MeshFilterInterface
{
	Q_OBJECT
	MESHLAB_PLUGIN_IID_EXPORTER(MESH_FILTER_INTERFACE_IID)
	Q_INTERFACES(MeshFilterInterface)

public:
	enum { FP_GPU_EXAMPLE  } ;

	ExtraSampleGPUPlugin();

    QString pluginName() const;
    FILTER_ARITY filterArity(QAction *) const {return SINGLE_MESH;}
	void initParameterSet(QAction *action,MeshModel &m, RichParameterList & parlst);

	QString filterName(FilterIDType filter) const;
	QString filterInfo(FilterIDType filter) const;
	bool applyFilter(QAction *filter, MeshDocument &md, const RichParameterList & /*parent*/, vcg::CallBackPos * cb) ;
    FilterClass getClass(QAction *a);
};


#endif
