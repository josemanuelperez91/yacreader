#ifndef __VIEWER_H
#define __VIEWER_H

#include <QMainWindow>

#include <QScrollArea>
#include <QAction>
#include <QTimer>
#include <QLabel>
#include <QPixmap>
#include <QKeyEvent>
#include <QResizeEvent>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QCloseEvent>
#include <QPropertyAnimation>
#include <QSettings>

#include "scroll_management.h"

class ComicDB;
class Comic;
class MagnifyingGlass;
class GoToFlow;
class BookmarksDialog;
class Render;
class GoToDialog;
class YACReaderTranslator;
class GoToFlowWidget;
class Bookmarks;
class PageLabelWidget; 
class NotificationsLabelWidget;

    class Viewer : public QScrollArea, public ScrollManagement
	{
		Q_OBJECT
	public:
		bool fullscreen; //TODO, change by the right use of windowState();
	public slots:
		void increaseZoomFactor();
		void decreaseZoomFactor();
		void setZoomFactor(qreal);
		qreal getZoomFactor();
	
		void prepareForOpening();
		void open(QString pathFile, int atPage = -1);
		void open(QString pathFile, const ComicDB & comic);
		void prev();
		void next();
		void showGoToDialog();
		void goTo(unsigned int page);
		void updatePage();
		void updateContentSize();
		void updateVerticalScrollBar();
		void updateOptions();
		void scrollDown();
		void scrollUp();
		void magnifyingGlassSwitch();
		void showMagnifyingGlass();
		void hideMagnifyingGlass();
		void informationSwitch();
		void updateInformation();
		void goToFlowSwitch();
		void showGoToFlow();
		void moveCursoToGoToFlow();
		void animateShowGoToFlow();
		void animateHideGoToFlow();
		void rotateLeft();
		void rotateRight();
		bool magnifyingGlassIsVisible() {return magnifyingGlassShowed;}
		void setBookmark(bool);
		void save();
		void doublePageSwitch();
		void doubleMangaPageSwitch();
		void resetContent();
		void setLoadingMessage();
		void setPageUnavailableMessage();
		void configureContent(QString msg);
		void hideCursor();
		void showCursor();
		void createConnections();
		void translatorSwitch();
		void animateShowTranslator();
		void animateHideTranslator();
virtual void mousePressEvent ( QMouseEvent * event );
virtual void mouseReleaseEvent ( QMouseEvent * event );
		void updateBackgroundColor(const QColor & color);
		void updateConfig(QSettings * settings);
		void showMessageErrorOpening();
		void showMessageErrorOpening(QString);
		void processCRCError(QString message);
		void setBookmarks();
		//deprecated
		void updateImageOptions();
		void updateFilters(int brightness, int contrast,int gamma);
		void showIsCoverMessage();
		void showIsLastMessage();
		int getCurrentPageNumber();
        void updateZoomRatio(float ratio);

	private:
		bool information;
		bool doublePage;
		bool doubleMangaPage;
	
		qreal zoom;
	
		PageLabelWidget * informationLabel;
		//QTimer * scroller;
		QPropertyAnimation * verticalScroller;
		int posByStep;
		int nextPos;
		GoToFlowWidget * goToFlow;
		QPropertyAnimation * showGoToFlowAnimation;
		GoToDialog * goToDialog;
		//!Image properties
		float adjustToWidthRatio;
		//! Comic
		//Comic * comic;
		int index;
		QPixmap *currentPage;
		BookmarksDialog * bd;
		bool wheelStop;
		Render * render;
		QTimer * hideCursorTimer;
		int direction;
		bool drag;
		int numScrollSteps;

		//!Widgets
		QLabel *content;

		YACReaderTranslator * translator;
		int translatorXPos;
		QPropertyAnimation * translatorAnimation;

		int yDragOrigin;
		int xDragOrigin;

		NotificationsLabelWidget * notificationsLabel;

		bool shouldOpenNext;
		bool shouldOpenPrevious;

	private:
		//!Magnifying glass
		MagnifyingGlass *mglass;
		bool magnifyingGlassShowed;
		bool restoreMagnifyingGlass;

		//! Manejadores de evento:
		void keyPressEvent(QKeyEvent * event);
		void resizeEvent(QResizeEvent * event);
		void wheelEvent(QWheelEvent * event);
		void mouseMoveEvent(QMouseEvent * event);

	public:
		Viewer(QWidget * parent = 0);
		~Viewer();
		void toggleFullScreen();
		const QPixmap * pixmap();
		//Comic * getComic(){return comic;}
		const BookmarksDialog * getBookmarksDialog(){return bd;}
		//returns the current index starting in 1 [1,nPages]
		unsigned int getIndex();
		void updateComic(ComicDB & comic);
	signals:
		void backgroundChanges();
		void pageAvailable(bool);
		void pageIsBookmark(bool);
		void reset();
		void openNextComic();
		void openPreviousComic();
	};

#endif
