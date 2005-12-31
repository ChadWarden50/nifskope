/***** BEGIN LICENSE BLOCK *****

BSD License

Copyright (c) 2005, NIF File Format Library and Tools
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. The name of the NIF File Format Library and Tools projectmay not be
   used to endorse or promote products derived from this software
   without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

***** END LICENCE BLOCK *****/

#ifndef POPUP_H
#define POPUP_H

#include <QAction>
#include <QColor>
#include <QCheckBox>
#include <QFrame>

class Popup : public QFrame
{
	Q_OBJECT
public:
	Popup( const QString & title, QWidget * parent );
	virtual ~Popup();
	
	QAction	*	popupAction() const { return aPopup; }
	
signals:
	void	aboutToHide();
	
public slots:
	virtual void popup();
	virtual void popup( const QPoint & p );
	
protected:
	virtual void showEvent( QShowEvent * );
	virtual void hideEvent( QHideEvent * );
	
private slots:
	virtual void popup( bool );
	
private:
	QAction	*	aPopup;
};

class ColorWheel : public QWidget
{
	Q_OBJECT
public:
	static QColor choose( const QColor & color, QWidget * parent );
	
	ColorWheel( QWidget * parent = 0 );
	
	Q_PROPERTY( QColor color READ getColor WRITE setColor STORED false );
	
	QColor getColor() const;
	
	QSize sizeHint() const;
	QSize minimumSizeHint() const;
	
	int heightForWidth( int width ) const;

signals:
	void sigColor( const QColor & );
	
public slots:
	void setColor( const QColor & );
	
protected:
	void paintEvent( QPaintEvent * e );
	void mousePressEvent( QMouseEvent * e );
	void mouseMoveEvent( QMouseEvent * e );

	void setColor( int x, int y );

private:
	double H, S, V;
	
	enum {
		Nope, Circle, Triangle
	} pressed;
};

QStringList selectMultipleDirs( const QString & title, const QStringList & def, QWidget * parent );

#endif
