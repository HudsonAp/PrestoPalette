#ifndef VISUALPALETTE_H
#define VISUALPALETTE_H

#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>

//#define TOTAL_SWATCHES 25
#define TOTAL_SWATCHES 40

class VisualPalette : public QWidget
{
	Q_OBJECT
public:
	explicit VisualPalette(QWidget *parent = 0);
	void setColorAt(int row, int column, const QColor &fillColor);
	void Formulate(QVector<QColor> combinedColors,
		       QVector<QColor> primaryColors, QVector<QColor> secondaryColors,
		       QColor neutral, int lastMixString, qreal stringLight, qreal stringDark,
		       bool enableLighting, QColor ambientColor, qreal ambientColorBrightness,
		       qreal power);

private:
	int lastTotalColors;
	int lastMixString;

	void resetSwatches();

signals:

public slots:

private:
	QGridLayout *layout;
	std::vector<QLabel*> swatches;
};

#endif // VISUALPALETTE_H