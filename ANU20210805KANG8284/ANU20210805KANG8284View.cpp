// ANU20210805KANG8284View.cpp: CANU20210805KANG8284View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ANU20210805KANG8284.h"
#endif

#include "ANU20210805KANG8284Doc.h"
#include "ANU20210805KANG8284View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CANU20210805KANG8284View

IMPLEMENT_DYNCREATE(CANU20210805KANG8284View, CView)

BEGIN_MESSAGE_MAP(CANU20210805KANG8284View, CView)
    // 표준 인쇄 명령입니다.
    ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
    ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
    ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
    ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CANU20210805KANG8284View 생성/소멸

CANU20210805KANG8284View::CANU20210805KANG8284View() noexcept
{
    // TODO: 여기에 생성 코드를 추가합니다.

}

CANU20210805KANG8284View::~CANU20210805KANG8284View()
{
}

BOOL CANU20210805KANG8284View::PreCreateWindow(CREATESTRUCT& cs)
{
    // TODO: CREATESTRUCT cs를 수정하여 여기에서
    //  Window 클래스 또는 스타일을 수정합니다.

    return CView::PreCreateWindow(cs);
}

// CANU20210805KANG8284View 그리기
CPoint pnt;

void DrawInvertedTriangle(CDC* pDC, int xCenter, int yCenter, int size)
{
    // Create a yellow brush
    CBrush yellowBrush(RGB(255, 255, 0)); // Yellow color

    // Select the yellow brush into the device context
    CBrush* pOldBrush = pDC->SelectObject(&yellowBrush);

    // Create a null pen to remove the outline
    CPen nullPen(PS_NULL, 0, RGB(0, 0, 0)); // PS_NULL로 윤곽선을 제거
    CPen* pOldPen = pDC->SelectObject(&nullPen);

    // Calculate the coordinates of the three points of the inverted triangle
    POINT points[3];
    points[0].x = xCenter;
    points[0].y = yCenter + size / 2; // Bottom point
    points[1].x = xCenter - size / 2;
    points[1].y = yCenter - size / 2; // Top-left point
    points[2].x = xCenter + size / 2;
    points[2].y = yCenter - size / 2; // Top-right point

    // Draw the filled inverted triangle
    pDC->Polygon(points, 3);

    // Restore the original objects
    pDC->SelectObject(pOldPen);
    pDC->SelectObject(pOldBrush);
}

void DrawTriangle(CDC* pDC, int xCenter, int yCenter, int size)
{
    // Create a yellow brush
    CBrush yellowBrush(RGB(255, 255, 0)); // Yellow color

    // Select the yellow brush into the device context
    CBrush* pOldBrush = pDC->SelectObject(&yellowBrush);

    // Create a null pen to remove the outline
    CPen nullPen(PS_NULL, 0, RGB(0, 0, 0)); // PS_NULL로 윤곽선을 제거
    CPen* pOldPen = pDC->SelectObject(&nullPen);

    // Calculate the coordinates of the three points of the triangle
    POINT points[3];
    points[0].x = xCenter;
    points[0].y = yCenter - size / 1; // Top point
    points[1].x = xCenter - size / 1;
    points[1].y = yCenter + size / 1; // Bottom-left point
    points[2].x = xCenter + size / 1;
    points[2].y = yCenter + size / 1; // Bottom-right point

    // Draw the filled triangle
    pDC->Polygon(points, 3);

    // Restore the original objects
    pDC->SelectObject(pOldPen);
    pDC->SelectObject(pOldBrush);
}

void CANU20210805KANG8284View::OnDraw(CDC* pDC)
{
    CANU20210805KANG8284Doc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    if (!pDoc)
        return;

    // TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
    int size = 300; // Size of the triangle (height)

    // Draw inverted triangle
    DrawInvertedTriangle(pDC, pnt.x, pnt.y, size);

    // Draw triangle on top of inverted triangle
    DrawTriangle(pDC, pnt.x, pnt.y - size / 4, size / 2);

    // Draw text at the center of the triangle
    pDC->TextOutW(pnt.x - 30, pnt.y-30, L"ANU_STAR");
}




// CANU20210805KANG8284View 인쇄

BOOL CANU20210805KANG8284View::OnPreparePrinting(CPrintInfo* pInfo)
{
    // 기본적인 준비
    return DoPreparePrinting(pInfo);
}

void CANU20210805KANG8284View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
    // TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CANU20210805KANG8284View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
    // TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CANU20210805KANG8284View 진단

#ifdef _DEBUG
void CANU20210805KANG8284View::AssertValid() const
{
    CView::AssertValid();
}

void CANU20210805KANG8284View::Dump(CDumpContext& dc) const
{
    CView::Dump(dc);
}

CANU20210805KANG8284Doc* CANU20210805KANG8284View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
    ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CANU20210805KANG8284Doc)));
    return (CANU20210805KANG8284Doc*)m_pDocument;
}
#endif //_DEBUG


// CANU20210805KANG8284View 메시지 처리기



void CANU20210805KANG8284View::OnMouseMove(UINT nFlags, CPoint point)
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    pnt = point;
    Invalidate(true);
    CView::OnMouseMove(nFlags, point);
}
