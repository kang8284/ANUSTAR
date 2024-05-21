
// ANU20210805KANG8284View.h: CANU20210805KANG8284View 클래스의 인터페이스
//

#pragma once


class CANU20210805KANG8284View : public CView
{
protected: // serialization에서만 만들어집니다.
	CANU20210805KANG8284View() noexcept;
	DECLARE_DYNCREATE(CANU20210805KANG8284View)

// 특성입니다.
public:
	CANU20210805KANG8284Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CANU20210805KANG8284View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // ANU20210805KANG8284View.cpp의 디버그 버전
inline CANU20210805KANG8284Doc* CANU20210805KANG8284View::GetDocument() const
   { return reinterpret_cast<CANU20210805KANG8284Doc*>(m_pDocument); }
#endif

